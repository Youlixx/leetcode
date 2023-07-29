#ifndef __00002_HPP__
#define __00002_HPP__

#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "../structures/SinglyLinkedList.hpp"
using namespace structure;

// 00002. Add Two Numbers - https://leetcode.com/problems/add-two-numbers/
namespace _00002 {
class Solution {
public:
  /// You are given two non-empty linked lists representing two non-negative 
  /// integers. The digits are stored in reverse order, and each of their nodes 
  /// contains a single digit. Add the two numbers and return the sum as a 
  /// linked list.
  /// You may assume the two numbers do not contain any leading zero, except 
  /// the number 0 itself.
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return addTwoNumbersWithCarray(l1, l2, 0);
  }

private:
  ListNode *addTwoNumbersWithCarray(ListNode *l1, ListNode *l2, int carry) {
    if (carry == 0 && l1 == nullptr && l2 == nullptr) {
      return nullptr;
    }

    int sum =
        carry + (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val);

    return new ListNode(
        sum % 10,
        addTwoNumbersWithCarray(l1 == nullptr ? nullptr : l1->next,
                                l2 == nullptr ? nullptr : l2->next, sum / 10));
  }
};
} // namespace _00002

TEST(_00002, Case1) {
  _00002::Solution solution{};

  ListNode l1{{2, 4, 3}};
  ListNode l2{{5, 6, 4}};

  std::vector<int> expected{7, 0, 8};

  std::vector<int> vector;
  ListNode *result = solution.addTwoNumbers(&l1, &l2);
  result->asVector(vector);

  ASSERT_VECTOR_EQUAL(vector, expected);

  delete result;
}

TEST(_00002, Case2) {
  _00002::Solution solution{};

  ListNode l1{0};
  ListNode l2{0};

  std::vector<int> expected{0};

  std::vector<int> vector;
  ListNode *result = solution.addTwoNumbers(&l1, &l2);
  result->asVector(vector);

  ASSERT_VECTOR_EQUAL(vector, expected);

  delete result;
}

TEST(_00002, Case3) {
  _00002::Solution solution{};

  ListNode l1{{9, 9, 9, 9, 9, 9, 9}};
  ListNode l2{{9, 9, 9, 9}};

  std::vector<int> expected{8, 9, 9, 9, 0, 0, 0, 1};

  std::vector<int> vector;
  ListNode *result = solution.addTwoNumbers(&l1, &l2);
  result->asVector(vector);

  ASSERT_VECTOR_EQUAL(vector, expected);

  delete result;
}

#endif
