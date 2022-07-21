#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // edge cases: left and right are head and end, i.e. no before, no after

    ListNode* before = nullptr;
    ListNode* cur_node = head;
    int cur_index = 1;

    // Go to left node
    while (cur_index != left) {
      before = cur_node;
      cur_node = cur_node->next;
      ++cur_index;
    }

    // iterative link reversal (2 node window)
    ListNode* window_left = cur_node;
    ListNode* window_right = cur_node->next;
    while (cur_index < right) {
      // First save the next iteration's state
      window_left = window_right;
      window_right = window_left->next;

      window_left->next = cur_node;

      cur_node = window_left;
      ++cur_index;
    }

    if (before != nullptr) {
      // link head of pertinent nodes to after
      before->next->next = window_right;
      // link before to head of pertinent nodes
      before->next = window_left;
    } else {
      head->next = window_right;
      head = window_left;
    }

    return head;
  }
};

template <typename T>
void print_vector(vector<T> vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i != vec.size() - 1) {
      cout << ", ";
    }
  }
  cout << "}";
}

int main() {
  Solution solution;

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
