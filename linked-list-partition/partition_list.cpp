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
  ListNode* partition(ListNode* head, int x) {
    ListNode* smaller_dummy = new ListNode(-1);
    ListNode* cur_smaller = smaller_dummy;
    ListNode* larger_dummy = new ListNode(-1);
    ListNode* cur_larger = larger_dummy;

    while (head != nullptr) {
      if (head->val >= x) {
        cur_larger->next = head;
        cur_larger = cur_larger->next;
      } else {
        cur_smaller->next = head;
        cur_smaller = cur_smaller->next;
      }
      head = head->next;
    }

    // the end of the larger list should ALWAYS BE NULL!
    cur_larger->next = nullptr;
    // connect the end of the smaller list to the non-dummy head of the larger list
    cur_smaller->next = larger_dummy->next;

    // return the non-dummy head of the smaller list
    return smaller_dummy->next;
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
