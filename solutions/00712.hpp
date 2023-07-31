#ifndef __00712_HPP__
#define __00712_HPP__

#include <gtest/gtest.h>

#include <string>

// 00712. Minimum ASCII Delete Sum for Two Strings -
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
namespace _00712 {
class Solution {
public:
  /// Given two strings s1 and s2, return the lowest ASCII sum of deleted
  /// characters to make two strings equal.
  int minimumDeleteSum(std::string s1, std::string s2) {
    int width = s2.size() + 1;
    int *dp = new int[(s1.size() + 1) * width];

    for (int index = 0; index < (s1.size() + 1) * width; index++) {
      dp[index] = 0;
    }

    for (int i = 1; i <= s1.size(); i++) {
      dp[i * width] = dp[(i - 1) * width] + s1[i - 1];
    }

    for (int j = 1; j <= s2.size(); j++) {
      dp[j] = dp[j - 1] + s2[j - 1];
    }

    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        dp[i * width + j] = s1[i - 1] == s2[j - 1]
                                ? dp[(i - 1) * width + j - 1]
                                : std::min(dp[(i - 1) * width + j] + s1[i - 1],
                                           dp[i * width + j - 1] + s2[j - 1]);
      }
    }

    return dp[s1.size() * width + s2.size()];
  }
};
} // namespace _00712

TEST(_00712, Case1) {
  _00712::Solution solution{};

  ASSERT_EQ(solution.minimumDeleteSum("sea", "eat"), 231);
}

TEST(_00712, Case2) {
  _00712::Solution solution{};

  ASSERT_EQ(solution.minimumDeleteSum("delete", "leet"), 403);
}

#endif
