// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    if (!head) {
      return false;
    }

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution solution;
}
