#include "CTM.h"
#include "concepts.h"
// pow for integral types
// x ^ y, x is integral and y is unsigned integral

namespace {

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

template <UnsignedIntegral Param, UnsignedIntegral Base>
constexpr size_t pow(const Param x, const Base y) {
  if (x == 0)
    return size_t(0);
  if (y == 0)
    return size_t(1);
  size_t acc = pow(x, y / 2);
  if (CTM::is_odd(y))
    return acc * acc * x;
  else
    return acc * acc;
}

template <SignedIntegral Param, UnsignedIntegral Base>
constexpr long long pow(const Param x, const Base y) {
  if (x == 0)
    return 0;
  if (y == 0)
    return 1;
  long long acc = pow(x, y / 2);
  if (CTM::is_odd(y))
    return acc * acc * x;
  else
    return acc * acc;
}

template <FloatingPoint Param, UnsignedIntegral Base>
constexpr double pow(const Param x, const Base y) {
  if (x == 0)
    return 0;
  if (y == 0)
    return 1;
  double acc = pow(x, y / 2);
  if (CTM::is_odd(y))
    return acc * acc * x;
  else
    return acc * acc;
}

//
// Other variants of pow is to be defined
//
} // namespace
