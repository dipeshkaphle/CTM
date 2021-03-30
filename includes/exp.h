#include "CTM.h"
#include "concepts.h"

namespace {

// e^x
constexpr double exp_taylor(double y) {
  if (std::is_constant_evaluated()) {
    assert(!CTM::is_inf(y));
    assert(!CTM::is_nan(y));
    double ret_val = 1;
    double x = y;
    x = CTM::abs(y);
    size_t N = 1000 + (CTM::abs(x)) * 10;
    for (size_t i = N - 1; i > 0; i--) {
      ret_val = 1 + (ret_val * x) / i;
    }
    if (x == (-y)) {
      return 1.0 / ret_val;
    }
    return ret_val;
  } else {
    return exp(y);
  }
}

constexpr double exp(double y) { return exp_taylor(y); }

} // namespace
