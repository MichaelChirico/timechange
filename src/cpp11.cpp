// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// get.cpp
cpp11::writable::list C_time_get(const cpp11::doubles& dt, const cpp11::strings& components, const int week_start);
extern "C" SEXP _timechange_C_time_get(SEXP dt, SEXP components, SEXP week_start) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_time_get(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles&>>(dt), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(components), cpp11::as_cpp<cpp11::decay_t<const int>>(week_start)));
  END_CPP11
}
// round.cpp
cpp11::writable::doubles C_time_ceiling(const cpp11::doubles dt, const std::string unit_name, const double nunits, const int week_start, const bool change_on_boundary);
extern "C" SEXP _timechange_C_time_ceiling(SEXP dt, SEXP unit_name, SEXP nunits, SEXP week_start, SEXP change_on_boundary) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_time_ceiling(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles>>(dt), cpp11::as_cpp<cpp11::decay_t<const std::string>>(unit_name), cpp11::as_cpp<cpp11::decay_t<const double>>(nunits), cpp11::as_cpp<cpp11::decay_t<const int>>(week_start), cpp11::as_cpp<cpp11::decay_t<const bool>>(change_on_boundary)));
  END_CPP11
}
// round.cpp
cpp11::writable::doubles C_time_floor(const cpp11::doubles dt, const std::string unit_name, const double nunits, const int week_start);
extern "C" SEXP _timechange_C_time_floor(SEXP dt, SEXP unit_name, SEXP nunits, SEXP week_start) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_time_floor(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles>>(dt), cpp11::as_cpp<cpp11::decay_t<const std::string>>(unit_name), cpp11::as_cpp<cpp11::decay_t<const double>>(nunits), cpp11::as_cpp<cpp11::decay_t<const int>>(week_start)));
  END_CPP11
}
// tzone.cpp
cpp11::strings C_local_tz();
extern "C" SEXP _timechange_C_local_tz() {
  BEGIN_CPP11
    return cpp11::as_sexp(C_local_tz());
  END_CPP11
}
// tzone.cpp
bool C_valid_tz(const cpp11::strings tz_name);
extern "C" SEXP _timechange_C_valid_tz(SEXP tz_name) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_valid_tz(cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(tz_name)));
  END_CPP11
}
// update.cpp
cpp11::writable::doubles C_time_update(const cpp11::doubles dt, const cpp11::list updates, const SEXP tz, const std::string roll_month, const cpp11::strings roll_dst, const int week_start, const bool exact);
extern "C" SEXP _timechange_C_time_update(SEXP dt, SEXP updates, SEXP tz, SEXP roll_month, SEXP roll_dst, SEXP week_start, SEXP exact) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_time_update(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles>>(dt), cpp11::as_cpp<cpp11::decay_t<const cpp11::list>>(updates), cpp11::as_cpp<cpp11::decay_t<const SEXP>>(tz), cpp11::as_cpp<cpp11::decay_t<const std::string>>(roll_month), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(roll_dst), cpp11::as_cpp<cpp11::decay_t<const int>>(week_start), cpp11::as_cpp<cpp11::decay_t<const bool>>(exact)));
  END_CPP11
}
// update.cpp
cpp11::writable::doubles C_time_add(const cpp11::doubles& dt, const cpp11::list periods, const std::string roll_month, const cpp11::strings roll_dst);
extern "C" SEXP _timechange_C_time_add(SEXP dt, SEXP periods, SEXP roll_month, SEXP roll_dst) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_time_add(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles&>>(dt), cpp11::as_cpp<cpp11::decay_t<const cpp11::list>>(periods), cpp11::as_cpp<cpp11::decay_t<const std::string>>(roll_month), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(roll_dst)));
  END_CPP11
}
// update.cpp
cpp11::writable::doubles C_force_tz(const cpp11::doubles dt, const cpp11::strings tz, const cpp11::strings roll_dst);
extern "C" SEXP _timechange_C_force_tz(SEXP dt, SEXP tz, SEXP roll_dst) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_force_tz(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles>>(dt), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(tz), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(roll_dst)));
  END_CPP11
}
// update.cpp
cpp11::writable::doubles C_force_tzs(const cpp11::doubles dt, const cpp11::strings tzs, const cpp11::strings tz_out, const cpp11::strings roll_dst);
extern "C" SEXP _timechange_C_force_tzs(SEXP dt, SEXP tzs, SEXP tz_out, SEXP roll_dst) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_force_tzs(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles>>(dt), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(tzs), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(tz_out), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(roll_dst)));
  END_CPP11
}
// update.cpp
cpp11::writable::doubles C_local_clock(const cpp11::doubles dt, const cpp11::strings tzs);
extern "C" SEXP _timechange_C_local_clock(SEXP dt, SEXP tzs) {
  BEGIN_CPP11
    return cpp11::as_sexp(C_local_clock(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles>>(dt), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings>>(tzs)));
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP C_parse_period(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"C_parse_period",             (DL_FUNC) &C_parse_period,             1},
    {"_timechange_C_force_tz",     (DL_FUNC) &_timechange_C_force_tz,     3},
    {"_timechange_C_force_tzs",    (DL_FUNC) &_timechange_C_force_tzs,    4},
    {"_timechange_C_local_clock",  (DL_FUNC) &_timechange_C_local_clock,  2},
    {"_timechange_C_local_tz",     (DL_FUNC) &_timechange_C_local_tz,     0},
    {"_timechange_C_time_add",     (DL_FUNC) &_timechange_C_time_add,     4},
    {"_timechange_C_time_ceiling", (DL_FUNC) &_timechange_C_time_ceiling, 5},
    {"_timechange_C_time_floor",   (DL_FUNC) &_timechange_C_time_floor,   4},
    {"_timechange_C_time_get",     (DL_FUNC) &_timechange_C_time_get,     3},
    {"_timechange_C_time_update",  (DL_FUNC) &_timechange_C_time_update,  7},
    {"_timechange_C_valid_tz",     (DL_FUNC) &_timechange_C_valid_tz,     1},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_timechange(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}