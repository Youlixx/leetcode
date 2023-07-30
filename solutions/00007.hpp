#ifndef __00007_HPP__
#define __00007_HPP__

#include <gtest/gtest.h>

#include <climits>

// 00007. Reverse Integer - https://leetcode.com/problems/reverse-integer/
namespace _00007 {
class Solution {
public:
  /// Given a signed 32-bit integer x, return x with its digits reversed. If
  /// reversing x causes the value to go outside the signed 32-bit integer
  /// range [-231, 231 - 1], then return 0.
  /// Assume the environment does not allow you to store 64-bit integers.
  int reverse(int x) {
    long result = 0;

    while (x != 0) {
      result *= 10;
      result += x % 10;
      x /= 10;
    }

    if (result > INT_MAX || result < INT_MIN) {
      return 0;
    }

    return static_cast<int>(result);
  }
};
} // namespace _00007

TEST(_00007, Case1) {
  _00007::Solution solution{};

  ASSERT_EQ(solution.reverse(123), 321);
}

TEST(_00007, Case2) {
  _00007::Solution solution{};

  ASSERT_EQ(solution.reverse(-123), -321);
}

TEST(_00007, Case3) {
  _00007::Solution solution{};

  ASSERT_EQ(solution.reverse(120), 21);
}

#endif
