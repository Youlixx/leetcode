#ifndef __00077_HPP__
#define __00077_HPP__

#include <gtest/gtest.h>

#include <vector>

#include "TestUtils.hpp"

// 00077. Combinations - https://leetcode.com/problems/combinations/
namespace _00077 {
class Solution {
public:
  /// Given two integers n and k, return all possible combinations of k numbers
  /// chosen from the range [1, n].
  /// You may return the answer in any order.
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result{};

    for (int start = 1; start <= n; start++) {
      result.push_back({start});
    }

    for (int index = 0; index < k - 1; index++) {
      std::vector<std::vector<int>> next{};

      for (auto &subset : result) {
        int lastElement = subset[index];

        if (lastElement != n) {
          for (int subIndex = lastElement + 1; subIndex <= n; subIndex++) {
            std::vector<int> newSet{subset};
            newSet.push_back(subIndex);
            next.push_back(newSet);
          }
        }
      }

      result = next;
    }

    return result;
  }
};
} // namespace _00077

TEST(_00077, Case1) {
  _00077::Solution solution{};

  std::vector<std::vector<int>> expected{{1, 2}, {1, 3}, {1, 4},
                                         {2, 3}, {2, 4}, {3, 4}};

  ASSERT_VECTOR_NESTED_EQUAL(solution.combine(4, 2), expected);
}

TEST(_00077, Case2) {
  _00077::Solution solution{};

  std::vector<std::vector<int>> expected{{1}};

  ASSERT_VECTOR_NESTED_EQUAL(solution.combine(1, 1), expected);
}

#endif
