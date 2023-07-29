#ifndef __00050_HPP__
#define __00050_HPP__

#include <gtest/gtest.h>

#include <climits>

// 00050. Pow(x, n) - https://leetcode.com/problems/powx-n/
namespace _00050 {
class Solution {
public:
  /// Implement pow(x, n), which calculates x raised to the power n.
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    } else if (n == INT_MIN) {
      return myPow(1 / x, INT_MAX) / x;
    } else if (n < 0) {
      return myPow(1 / x, -n);
    } else if (n % 2 == 0) {
      return myPow(x * x, n >> 1);
    } else {
      return x * myPow(x * x, (n - 1) >> 1);
    }
  }
};
} // namespace _00050

TEST(_00050, Case1) {
  _00050::Solution solution{};

  ASSERT_NEAR(solution.myPow(2.00000, 10), 1024.00000, 1e-5);
}

TEST(_00050, Case2) {
  _00050::Solution solution{};

  ASSERT_NEAR(solution.myPow(2.10000, 3), 9.26100, 1e-5);
}

TEST(_00050, Case3) {
  _00050::Solution solution{};

  ASSERT_NEAR(solution.myPow(2.00000, -2), 0.25000, 1e-5);
}

#endif
