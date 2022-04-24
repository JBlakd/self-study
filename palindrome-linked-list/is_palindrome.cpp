// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    if (!head->next) {
      return true;
    }

    // find middle
    int count = 1;
    ListNode *cur_node = head;
    while (cur_node->next) {
      count++;
      cur_node = cur_node->next;
    }

    // Two pointers
    ListNode *left = head;
    int left_end = 0;
    ListNode *right = head;
    int right_start;
    if (count % 2 == 0) {
      right_start = count / 2;
      left_end = right_start - 1;
      for (int i = 0; i < right_start; i++) {
        right = right->next;
      }
    } else {
      right_start = count / 2 + 1;
      left_end = right_start - 2;
      for (int i = 0; i < right_start; i++) {
        right = right->next;
      }
    }

    for (int i = 0; i <= left_end; i++) {
      if (left->val != right->val) {
        return false;
      }

      if (i < left_end) {
        left = left->next;
        right = right->next;
      }
    }

    return true;
  }
};

int main() {
  Solution solution;
  vector<int> input;
  vector<ListNode> nodes;

  input = {1, 2, 2, 1};
  for (int i = 0; i < input.size(); i++) {
    nodes.push_back(ListNode(input[i]));
  }
  for (int i = 0; i < input.size() - 1; i++) {
    nodes[i].next = &nodes[i + 1];
  }
  cout << solution.isPalindrome(&nodes[0]);
}
