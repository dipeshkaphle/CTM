#include "CTM.h"
#include <iostream>
#include <type_traits>

int main() {
  constexpr std::size_t ans = CTM::factorial(10u);
  constexpr std::size_t ans1 = CTM::abs(10);
  constexpr std::size_t ans2 = CTM::abs(-10);
  constexpr double ans3 = CTM::abs(-10.5);
  constexpr int ans4 = CTM::gcd(-10, -2);
  constexpr double x = CTM::floor(10);

  std::cout << ans << ' ' << ans1 << ' ' << ' ' << ans2 << ' ' << ans3 << ' '
            << ans4 << ' ' << x << std::endl;
}
