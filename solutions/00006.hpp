#ifndef __00006_HPP__
#define __00006_HPP__

#include <gtest/gtest.h>

#include <string>
#include <vector>

// 00006. Zigzag Conversion - https://leetcode.com/problems/zigzag-conversion/
namespace _00006 {
class Solution {
public:
  /// The string "PAYPALISHIRING" is written in a zigzag pattern on a given
  /// number of rows like this: (you may want to display this pattern in a
  /// fixed font for better legibility)
  /// P   A   H   N
  /// A P L S I I G
  /// Y   I   R
  /// And then read line by line: "PAHNAPLSIIGYIR".
  /// Write the code that will take a string and make this conversion given a
  /// number of rows
  std::string convert(std::string s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    std::string result;

    for (int index = 0; index < numRows; index++) {
      std::vector<int> indices = getIndices(numRows, index, s.size());

      for (const auto &offset : indices) {
        result += s[offset];
      }
    }

    return result;
  }

private:
  std::vector<int> getIndices(int numRows, int row, int max) {
    int first = 2 * (numRows - 1 - row);
    int second = 2 * row;

    std::vector<int> indices{};

    if (first == 0 || second == 0) {
      for (int index = row; index < max; index += first + second) {
        indices.push_back(index);
      }
    } else {
      for (int index = row; index < max; index += first + second) {
        indices.push_back(index);

        if (index + first < max) {
          indices.push_back(index + first);
        }
      }
    }

    return indices;
  }
};
} // namespace _00006

TEST(_00006, Case1) {
  _00006::Solution solution{};

  ASSERT_EQ(solution.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST(_00006, Case2) {
  _00006::Solution solution{};

  ASSERT_EQ(solution.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(_00006, Case3) {
  _00006::Solution solution{};

  ASSERT_EQ(solution.convert("A", 1), "A");
}

#endif
