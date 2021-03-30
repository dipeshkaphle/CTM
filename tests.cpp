#include "CTM.h"
#include <iostream>

int main() {
  constexpr std::size_t ans = CTM::factorial(10u);
  static_assert(ans == 3628800, "");

  constexpr std::size_t ans1 = CTM::abs(10);
  static_assert(ans1 == 10, "");

  constexpr std::size_t ans2 = CTM::abs(-10);
  static_assert(ans2 == 10, "");

  constexpr double ans3 = CTM::abs(-10.5);
  static_assert(ans3 == 10.5, "");

  constexpr int ans4 = CTM::gcd(-10, -2);
  static_assert(ans4 == -2, "");

  constexpr double x = CTM::floor(10);
  static_assert(x == 10, "");

  constexpr auto pow_ans = CTM::power_v<2, 5>;
  static_assert(pow_ans == 32, "");
  static_assert(CTM::power_v<0, 10> == 0, "");
  static_assert(CTM::power_v<2, 0> == 1, "");
  constexpr size_t constexpr_pow = CTM::pow(2u, 10u);
  static_assert(constexpr_pow == 1024, "");
  constexpr long long constexpr_pow_sgnd = CTM::pow(-10, 3u);
  static_assert(constexpr_pow_sgnd == -1000, "");
  constexpr double constexpr_pow_dbl = CTM::pow(-10.0, 3u);
  static_assert(constexpr_pow_dbl == -1000.00, "");
}
