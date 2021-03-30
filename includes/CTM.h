#pragma once

#include "concepts.h"
//
// ===============================================================
// ===============================================================
// ===============================================================

namespace CTM {

// factorial
template <UnsignedIntegral T>
constexpr std::size_t factorial(const T n) noexcept {
  if (n == 0)
    return 1;
  std::size_t ans = 1;
  std::size_t limit = static_cast<std::size_t>(n);
  for (std::size_t i = 2; i <= limit; i++) {
    ans *= i;
  }
  return ans;
}

// gcd
template <Integral T> constexpr T gcd(const T x, const T y) noexcept {
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

// is_even
template <Integral T> constexpr bool is_even(const T x) noexcept {
  return x % 2 == 0;
}

// is_odd
template <Integral T> constexpr bool is_odd(const T x) noexcept {
  return x % 2 == 1;
}

// is_inf for doubles
template <FloatingPoint T> constexpr bool is_inf(const T x) noexcept {
  if (std::is_constant_evaluated())
    return (x == T(INFINITY)) || (x == T(-INFINITY));
  else
    return std::isinf(x);
}

// is_nan for doubles
template <FloatingPoint T> constexpr bool is_nan(const T x) noexcept {
  // https://stackoverflow.com/questions/570669/checking-if-a-double-or-float-is-nan-in-c
  if (std::is_constant_evaluated()) {
    return (x != x);
  } else
    return std::isnan(x);
}

// abs
template <FloatingPoint T> constexpr T abs(const T n) {
  assert(!CTM::is_inf(n));
  assert(!CTM::is_nan(n));
  return (n == T(0) ? T(0) : (n < T(0) ? -n : n));
}
// abs for integral types
template <Integral T> constexpr T abs(const T n) noexcept {
  return (n == T(0) ? T(0) : (n < T(0) ? -n : n));
}

// ceil for flaoting types
template <FloatingPoint T> constexpr long long ceil(const T x) {
  assert(!CTM::is_inf(x));
  assert(!CTM::is_nan(x));
  return x == ((long long)x) ? (long long)x : T((long long)x + 1);
}
// ceil for integral types
template <Integral T> constexpr T ceil(const T x) noexcept { return x; }

// floor for floating types
template <FloatingPoint T> constexpr long long floor(const T x) {
  assert(!CTM::is_inf(x));
  assert(!CTM::is_nan(x));
  return x == ((long long)x) ? (long long)x : T((long long)x);
}
// floor for integral types
template <Integral T> constexpr T floor(const T x) noexcept { return x; }

// max and min, no need because std::max and std::min are already constexpr

// power with templates
template <size_t x, size_t y> struct power {
  static constexpr size_t value =
      (power<x, y / 2>::value * power<x, y / 2>::value) *
      (CTM::is_odd(y) ? x : 1);
};

template <size_t y> struct power<0, y> { static constexpr size_t value = 0; };

template <size_t x> struct power<x, 0> { static constexpr size_t value = 1; };

template <size_t x, size_t y>
static constexpr size_t power_v = power<x, y>::value;

//
// pow for integral types
// x ^ y, x is integral and y is unsigned integral
template <Integral Param, UnsignedIntegral Base>
constexpr auto pow(const Param &x, const Base &y) {
  if constexpr (std::is_signed_v<Param>) {
    if (x == 0)
      return (long long)0;
    if (y == 0)
      return (long long)1;
    long long acc = CTM::pow(x, y / 2);
    if (CTM::is_odd(y))
      return acc * acc * x;
    else
      return acc * acc;
  } else {
    if (x == 0)
      return size_t(0);
    if (y == 0)
      return size_t(1);
    size_t acc = CTM::pow(x, y / 2);
    if (CTM::is_odd(y))
      return acc * acc * x;
    else
      return acc * acc;
  }
}
//
// Other variants of pow is to be defined
//

} // namespace CTM
