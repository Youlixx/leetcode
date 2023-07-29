#ifndef __00004_HPP__
#define __00004_HPP__

#include <gtest/gtest.h>

#include <vector>

// 00004. Median of Two Sorted Arrays -
// https://leetcode.com/problems/median-of-two-sorted-arrays/
namespace _00004 {
class Solution {
public:
  /// Given two sorted arrays nums1 and nums2 of size m and n respectively,
  /// return the median of the two sorted arrays.
  /// The overall run time complexity should be O(log (m+n)).
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    if (nums1.size() < nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int left = 0;
    int right = nums2.size() * 2;

    while (left <= right) {
      int mid2 = (left + right) / 2;
      int mid1 = nums1.size() + nums2.size() - mid2;

      double left1 =
          mid1 <= 0 ? -DBL_MAX : static_cast<double>(nums1[(mid1 - 1) / 2]);
      double left2 =
          mid2 <= 0 ? -DBL_MAX : static_cast<double>(nums2[(mid2 - 1) / 2]);
      double right1 = mid1 >= nums1.size() * 2
                          ? DBL_MAX
                          : static_cast<double>(nums1[mid1 / 2]);
      double right2 = mid2 >= nums2.size() * 2
                          ? DBL_MAX
                          : static_cast<double>(nums2[mid2 / 2]);

      if (left1 > right2) {
        left = mid2 + 1;
      } else if (left2 > right1) {
        right = mid2 - 1;
      } else {
        return (std::max(left1, left2) + std::min(right1, right2)) / 2;
      }
    }

    return -1.0;
  }
};
} // namespace _00004

TEST(_00004, Case1) {
  _00004::Solution solution{};

  std::vector<int> nums1{1, 3};
  std::vector<int> nums2{2};

  ASSERT_NEAR(solution.findMedianSortedArrays(nums1, nums2), 2.0, 1e-5);
}

TEST(_00004, Case2) {
  _00004::Solution solution{};

  std::vector<int> nums1{1, 2};
  std::vector<int> nums2{3, 4};

  ASSERT_NEAR(solution.findMedianSortedArrays(nums1, nums2), 2.5, 1e-5);
}

TEST(_00004, Case3) {
  _00004::Solution solution{};

  std::vector<int> nums1{};
  std::vector<int> nums2{0};

  ASSERT_NEAR(solution.findMedianSortedArrays(nums1, nums2), 0.0, 1e-5);
}

#endif
