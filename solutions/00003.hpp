#ifndef __00003_HPP__
#define __00003_HPP__

#include <gtest/gtest.h>

#include <string>

// 00003. Longest Substring Without Repeating Characters -
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
namespace _00003 {
class Solution {
public:
  /// Given a string s, find the length of the longest substring without
  /// repeating characters.
  int lengthOfLongestSubstring(std::string s) {
    std::string current = "";
    int largest = 0;

    for (const auto &character : s) {
      size_t position = current.find(character);

      if (position != std::string::npos) {
        current = current.substr(position + 1);
      }

      current += character;

      if (current.size() > largest) {
        largest = current.size();
      }
    }

    return largest;
  }
};
} // namespace _00003

TEST(_00003, Case1) {
  _00003::Solution solution{};

  ASSERT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(_00003, Case2) {
  _00003::Solution solution{};

  ASSERT_EQ(solution.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(_00003, Case3) {
  _00003::Solution solution{};

  ASSERT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
}

#endif
