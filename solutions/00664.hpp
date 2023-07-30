#ifndef __00664_HPP__
#define __00664_HPP__

#include <gtest/gtest.h>

#include <optional>
#include <string>

// 00664. Strange Printer - https://leetcode.com/problems/strange-printer/
namespace _00664 {
class Solution {
public:
  /// There is a strange printer with the following two special properties:
  /// - The printer can only print a sequence of the same character each time.
  /// - At each turn, the printer can print new characters starting from and
  ///   ending at any place and will cover the original existing characters.
  /// Given a string s, return the minimum number of turns the printer needed
  /// to print it.
  int strangePrinter(std::string s) {
    int *dp = new int[s.size() * s.size()];

    for (int index = 0; index < s.size() * s.size(); index++) {
      dp[index] = -1;
    }

    int result = getNumberOfTurns(dp, s, 0, s.size() - 1);

    delete[] dp;

    return result + 1;
  }

private:
  int getNumberOfTurns(int *dp, std::string &s, int left, int right) {
    int index = left * s.size() + right;

    if (dp[index] != -1) {
      return dp[index];
    }

    dp[index] = s.size();
    std::optional<int> lastSplit = {};

    for (int split = left; split < right; split++) {
      if (s[split] != s[right] && !lastSplit.has_value()) {
        lastSplit = split;
      }

      if (lastSplit.has_value()) {
        dp[index] = std::min(
            dp[index], 1 + getNumberOfTurns(dp, s, lastSplit.value(), split) +
                           getNumberOfTurns(dp, s, split + 1, right));
      }
    }

    if (!lastSplit.has_value()) {
      dp[index] = 0;
    }

    return dp[index];
  }
};
} // namespace _00664

TEST(_00664, Case1) {
  _00664::Solution solution{};

  ASSERT_EQ(solution.strangePrinter("aaabbb"), 2);
}

TEST(_00664, Case2) {
  _00664::Solution solution{};

  ASSERT_EQ(solution.strangePrinter("aba"), 2);
}

TEST(_00664, Case3) {
  _00664::Solution solution{};

  ASSERT_EQ(solution.strangePrinter("leetcode"), 6);
}

#endif
