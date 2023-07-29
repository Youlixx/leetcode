#ifndef __00001_HPP__
#define __00001_HPP__

#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

#include "utils.hpp"

// 00001. Two Sum - https://leetcode.com/problems/two-sum/
namespace _00001 {
class Solution {
public:
  /// Given an array of integers nums and an integer target, return indices of
  /// the two numbers such that they add up to target. You may assume that each
  /// input would have exactly one solution, and you may not use the same
  /// element twice. You can return the answer in any order.
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> indices{nums.size()};

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];

      if (indices.find(complement) != indices.end()) {
        return {indices[complement], i};
      } else {
        indices.insert({nums[i], i});
      }
    }

    return {-1, -1};
  }
};
} // namespace _00001

TEST(_00001, Case1) {
  _00001::Solution solution{};

  std::vector<int> nums{2, 7, 11, 15};
  std::vector<int> expected{0, 1};

  ASSERT_VECTOR_EQUAL(solution.twoSum(nums, 9), expected);
}

TEST(_00001, Case2) {
  _00001::Solution solution{};

  std::vector<int> nums{3, 2, 4};
  std::vector<int> expected{1, 2};

  ASSERT_VECTOR_EQUAL(solution.twoSum(nums, 6), expected);
}

TEST(_00001, Case3) {
  _00001::Solution solution{};

  std::vector<int> nums{3, 3};
  std::vector<int> expected{0, 1};

  ASSERT_VECTOR_EQUAL(solution.twoSum(nums, 6), expected);
}

#endif
