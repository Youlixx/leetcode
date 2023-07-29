#ifndef __00852_HPP__
#define __00852_HPP__

#include <gtest/gtest.h>

#include <vector>

// 00852. Peak Index in a Mountain Array -
// https://leetcode.com/problems/peak-index-in-a-mountain-array/
namespace _00852 {
class Solution {
public:
  /// An array arr is a mountain if the following properties hold:
  /// - arr.length >= 3
  /// - There exists some i with 0 < i < arr.length - 1 such that:
  ///   - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  ///   - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
  /// Given a mountain array arr, return the index i such that
  /// - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  /// - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
  /// You must solve it in O(log(arr.length)) time complexity.
  int peakIndexInMountainArray(std::vector<int> &arr) {
    int left = 1;
    int right = arr.size() - 2;

    while (right - left > 1) {
      int position = (left + right) / 2;
      int slopeLeft = arr[position - 1];
      int slopeMiddle = arr[position];
      int slopeRight = arr[position + 1];

      if (slopeMiddle > slopeLeft && slopeMiddle > slopeRight) {
        return position;
      } else if (slopeMiddle > slopeLeft) {
        left = position;
      } else {
        right = position;
      }
    }

    if (arr[right] > arr[left]) {
      return right;
    }

    return left;
  }
};
} // namespace _00852

TEST(_00852, Case1) {
  _00852::Solution solution{};

  std::vector<int> arr{0, 1, 0};

  ASSERT_EQ(solution.peakIndexInMountainArray(arr), 1);
}

TEST(_00852, Case2) {
  _00852::Solution solution{};

  std::vector<int> arr{0, 2, 1, 0};

  ASSERT_EQ(solution.peakIndexInMountainArray(arr), 1);
}

TEST(_00852, Case3) {
  _00852::Solution solution{};

  std::vector<int> arr{0, 10, 5, 2};

  ASSERT_EQ(solution.peakIndexInMountainArray(arr), 1);
}

#endif
