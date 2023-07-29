#ifndef __00005_HPP__
#define __00005_HPP__

#include <gtest/gtest.h>

#include <string>

// 00005. Longest Palindromic Substring -
// https://leetcode.com/problems/longest-palindromic-substring/
namespace _00005 {
class Solution {
public:
  /// Given a string s, return the longest palindromic substring in s.
  std::string longestPalindrome(std::string s) {
    if (s.size() == 1) {
      return s;
    }

    std::string longest{};

    for (int index = 0; index < s.size() - 1; index++) {
      for (int offset = 0; offset < 2; offset++) {
        std::string candidate = expandFromCenter(s, index, index + offset);

        if (candidate.size() > longest.size()) {
          longest = candidate;
        }
      }
    }

    return longest;
  }

private:
  std::string expandFromCenter(std::string &s, int left, int right) {
    if (s[right] != s[left]) {
      return {};
    }

    while (left > 0 && right < s.size() - 1 && s[left] == s[right]) {
      left--;
      right++;
    }

    if (s[left] != s[right]) {
      left++;
    } else {
      right++;
    }

    return {&s[left], &s[right]};
  }
};
} // namespace _00005

TEST(_00005, Case1) {
  _00005::Solution solution{};

  ASSERT_EQ(solution.longestPalindrome("babad"), "bab");
}

TEST(_00005, Case2) {
  _00005::Solution solution{};

  ASSERT_EQ(solution.longestPalindrome("cbbd"), "bb");
}

TEST(_00005, Case3) {
  _00005::Solution solution{};

  ASSERT_EQ(solution.longestPalindrome("eabcb"), "bcb");
}

#endif
