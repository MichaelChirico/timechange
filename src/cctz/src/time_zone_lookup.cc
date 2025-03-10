// Copyright 2016 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   https://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#include "time_zone.h"

#if defined(__ANDROID__)
#include <sys/system_properties.h>
#if defined(__ANDROID_API__) && __ANDROID_API__ >= 21
#include <dlfcn.h>
#endif
#endif

#if defined(__APPLE__)
#include <CoreFoundation/CFTimeZone.h>
#include <vector>
#endif

#include <cstdlib>
#include <cstring>
#include <string>

#include "time_zone_fixed.h"
#include "time_zone_impl.h"

namespace cctz {

#if defined(__ANDROID__) && defined(__ANDROID_API__) && __ANDROID_API__ >= 21
namespace {
// Android 'L' removes __system_property_get() from the NDK, however
// it is still a hidden symbol in libc so we use dlsym() to access it.
// See Chromium's base/sys_info_android.cc for a similar example.

using property_get_func = int (*)(const char*, char*);

property_get_func LoadSystemPropertyGet() {
  int flag = RTLD_LAZY | RTLD_GLOBAL;
#if defined(RTLD_NOLOAD)
  flag |= RTLD_NOLOAD;  // libc.so should already be resident
#endif
  if (void* handle = dlopen("libc.so", flag)) {
    void* sym = dlsym(handle, "__system_property_get");
    dlclose(handle);
    return reinterpret_cast<property_get_func>(sym);
  }
  return nullptr;
}

int __system_property_get(const char* name, char* value) {
  static property_get_func system_property_get = LoadSystemPropertyGet();
  return system_property_get ? system_property_get(name, value) : -1;
}

}  // namespace
#endif

std::string time_zone::name() const {
  return effective_impl().Name();
}

time_zone::absolute_lookup time_zone::lookup(
    const time_point<seconds>& tp) const {
  return effective_impl().BreakTime(tp);
}

time_zone::civil_lookup time_zone::lookup(const civil_second& cs) const {
  return effective_impl().MakeTime(cs);
}

bool time_zone::next_transition(const time_point<seconds>& tp,
                                civil_transition* trans) const {
  return effective_impl().NextTransition(tp, trans);
}

bool time_zone::prev_transition(const time_point<seconds>& tp,
                                civil_transition* trans) const {
  return effective_impl().PrevTransition(tp, trans);
}

std::string time_zone::version() const {
  return effective_impl().Version();
}

std::string time_zone::description() const {
  return effective_impl().Description();
}

const time_zone::Impl& time_zone::effective_impl() const {
  if (impl_ == nullptr) {
    // Dereferencing an implicit-UTC time_zone is expected to be
    // rare, so we don't mind paying a small synchronization cost.
    return *time_zone::Impl::UTC().impl_;
  }
  return *impl_;
}

bool load_time_zone(const std::string& name, time_zone* tz) {
  return time_zone::Impl::LoadTimeZone(name, tz);
}

time_zone utc_time_zone() {
  return time_zone::Impl::UTC();  // avoid name lookup
}

time_zone fixed_time_zone(const seconds& offset) {
  time_zone tz;
  load_time_zone(FixedOffsetToName(offset), &tz);
  return tz;
}

time_zone local_time_zone() {
  const char* zone = ":localtime";
#if defined(__ANDROID__)
  char sysprop[PROP_VALUE_MAX];
  if (__system_property_get("persist.sys.timezone", sysprop) > 0) {
    zone = sysprop;
  }
#endif
#if defined(__APPLE__)
  std::vector<char> buffer;
  CFTimeZoneRef tz_default = CFTimeZoneCopyDefault();
  if (CFStringRef tz_name = CFTimeZoneGetName(tz_default)) {
    CFStringEncoding encoding = kCFStringEncodingUTF8;
    CFIndex length = CFStringGetLength(tz_name);
    buffer.resize(CFStringGetMaximumSizeForEncoding(length, encoding) + 1);
    if (CFStringGetCString(tz_name, &buffer[0], buffer.size(), encoding)) {
      zone = &buffer[0];
    }
  }
  CFRelease(tz_default);
#endif

  // Allow ${TZ} to override to default zone.
  char* tz_env = nullptr;
#if defined(_MSC_VER)
  _dupenv_s(&tz_env, nullptr, "TZ");
#else
  tz_env = std::getenv("TZ");
#endif
  if (tz_env) zone = tz_env;

  // We only support the "[:]<zone-name>" form.
  if (*zone == ':') ++zone;

  // Map "localtime" to a system-specific name, but
  // allow ${LOCALTIME} to override the default name.
  char* localtime_env = nullptr;
  if (strcmp(zone, "localtime") == 0) {
#if defined(_MSC_VER)
    // System-specific default is just "localtime".
    _dupenv_s(&localtime_env, nullptr, "LOCALTIME");
#else
    zone = "/etc/localtime";  // System-specific default.
    localtime_env = std::getenv("LOCALTIME");
#endif
    if (localtime_env) zone = localtime_env;
  }

  const std::string name = zone;
#if defined(_MSC_VER)
  free(localtime_env);
  free(tz_env);
#endif

  time_zone tz;
  load_time_zone(name, &tz);  // Falls back to UTC.
  // TODO: Follow the RFC3339 "Unknown Local Offset Convention" and
  // arrange for %z to generate "-0000" when we don't know the local
  // offset because the load_time_zone() failed and we're using UTC.
  return tz;
}

}  // namespace cctz
