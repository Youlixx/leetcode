#ifndef __STUCTURE_SINGLY_LINKED_LIST_HPP__
#define __STUCTURE_SINGLY_LINKED_LIST_HPP__

#include <vector>

namespace structure {
struct ListNode {
  int val;

  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  ListNode(std::vector<int> values) : val{values[0]}, next{nullptr} {
    values.erase(values.begin());

    if (!values.empty()) {
      next = new ListNode(values);
    }
  }

  ~ListNode() {
    if (next != nullptr) {
      delete next;

      next = nullptr;
    }
  }

  bool operator==(const ListNode &other) {
    if (val != other.val) {
      return false;
    }

    if ((next == nullptr && other.next != nullptr) ||
        (next != nullptr && other.next == nullptr)) {
      return false;
    }

    if (next == nullptr) {
      return true;
    }

    return (*next) == (*other.next);
  }

  bool operator!=(const ListNode &other) { return !((*this) == other); }

  void asVector(std::vector<int> &vector) {
    vector.push_back(val);

    if (next != nullptr) {
      next->asVector(vector);
    }
  }
};
} // namespace structure

#endif
