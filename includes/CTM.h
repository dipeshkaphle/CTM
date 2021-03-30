#pragma once

#include <cassert>
#include <cmath>
#include <concepts>
#include <numeric>
#include <stdexcept>
#include <type_traits>

// ===============================================================
// ===============================================================
// ===============================================================
//
// Concepts used
//
template <typename T> concept Integral = std::integral<T>;

template <typename T> concept UnsignedIntegral = std::unsigned_integral<T>;

template <typename T> concept FloatingPoint = std::floating_point<T>;

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;
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

template <Integral T> constexpr bool is_even(const T x) noexcept {
  return x % 2 == 0;
}

template <Integral T> constexpr bool is_odd(const T x) noexcept {
  return x % 2 == 1;
}

template <FloatingPoint T> constexpr bool is_inf(const T x) noexcept {
  if (std::is_constant_evaluated())
    return (x == T(INFINITY)) || (x == T(-INFINITY));
  else
    return std::isinf(x);
}

template <FloatingPoint T> constexpr bool is_nan(const T x) noexcept {
  // https://stackoverflow.com/questions/570669/checking-if-a-double-or-float-is-nan-in-c
  if (std::is_constant_evaluated()) {
    return (x != x);
  } else
    return std::isnan(x);
}
//
//
//
// abs
template <FloatingPoint T> constexpr T abs(const T n) {
  assert(!CTM::is_inf(n));
  assert(!CTM::is_nan(n));
  return (n == T(0) ? T(0) : (n < T(0) ? -n : n));
}

template <Integral T> constexpr T abs(const T n) noexcept {
  return (n == T(0) ? T(0) : (n < T(0) ? -n : n));
}

template <FloatingPoint T> constexpr long long ceil(const T x) {
  assert(!CTM::is_inf(x));
  assert(!CTM::is_nan(x));
  return x == ((long long)x) ? (long long)x : T((long long)x + 1);
}

template <Integral T> constexpr T ceil(const T x) noexcept { return x; }

// floor
template <Integral T> constexpr T floor(const T x) noexcept { return x; }

template <FloatingPoint T> constexpr long long floor(const T x) {
  assert(!CTM::is_inf(x));
  assert(!CTM::is_nan(x));
  return x == ((long long)x) ? (long long)x : T((long long)x);
}

} // namespace CTM