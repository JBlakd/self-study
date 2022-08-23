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
  bool isPalindrome(ListNode* head) {
    if (head->next == nullptr) {
      return true;
    }

    if (head->next->next == nullptr) {
      return (head->val == head->next->val);
    }

    // phase 1: use slow & fast pointers to find midpoint of linked list
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // phase 2: slow is now at the correct position.
    // start reversing all subsequent nodes to point in this direction
    ListNode* slow_prev = nullptr;
    ListNode* slow_next = nullptr;
    while (slow != nullptr) {
      slow_next = slow->next;
      slow->next = slow_prev;
      slow_prev = slow;
      slow = slow_next;
    }

    // phase 3: now slow_prev is at the opposite end to head
    // the palidromic comparison is ready
    while (true) {
      if (slow_prev->val != head->val) {
        return false;
      }

      if (slow_prev->next == head->next) {
        break;
      }
      if (head->next == slow_prev) {
        return (head->val == slow_prev->val);
      }

      slow_prev = slow_prev->next;
      head = head->next;
    }

    return true;
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
  vector<int> input;
  vector<ListNode*> nodes;
  bool output;

  input = {7};
  nodes = vector<ListNode*>(input.size(), nullptr);
  for (int i = 0; i < input.size(); ++i) {
    nodes[i] = new ListNode(input[i]);
  }
  for (int i = 0; i < input.size() - 1; ++i) {
    nodes[i]->next = nodes[i + 1];
  }
  output = solution.isPalindrome(nodes[0]);
  cout << ((output) ? "true\n" : "false\n");
  assert(output == true);

  input = {7, 3};
  nodes = vector<ListNode*>(input.size(), nullptr);
  for (int i = 0; i < input.size(); ++i) {
    nodes[i] = new ListNode(input[i]);
  }
  for (int i = 0; i < input.size() - 1; ++i) {
    nodes[i]->next = nodes[i + 1];
  }
  output = solution.isPalindrome(nodes[0]);
  cout << ((output) ? "true\n" : "false\n");
  assert(output == false);

  input = {3, 3};
  nodes = vector<ListNode*>(input.size(), nullptr);
  for (int i = 0; i < input.size(); ++i) {
    nodes[i] = new ListNode(input[i]);
  }
  for (int i = 0; i < input.size() - 1; ++i) {
    nodes[i]->next = nodes[i + 1];
  }
  output = solution.isPalindrome(nodes[0]);
  cout << ((output) ? "true\n" : "false\n");
  assert(output == true);

  input = {1, 2, 2, 1};
  nodes = vector<ListNode*>(input.size(), nullptr);
  for (int i = 0; i < input.size(); ++i) {
    nodes[i] = new ListNode(input[i]);
  }
  for (int i = 0; i < input.size() - 1; ++i) {
    nodes[i]->next = nodes[i + 1];
  }
  output = solution.isPalindrome(nodes[0]);
  cout << ((output) ? "true\n" : "false\n");
  assert(output == true);

  input = {1, 6, 2, 1};
  nodes = vector<ListNode*>(input.size(), nullptr);
  for (int i = 0; i < input.size(); ++i) {
    nodes[i] = new ListNode(input[i]);
  }
  for (int i = 0; i < input.size() - 1; ++i) {
    nodes[i]->next = nodes[i + 1];
  }
  output = solution.isPalindrome(nodes[0]);
  cout << ((output) ? "true\n" : "false\n");
  assert(output == false);

  input = {1, 2, 3, 2, 1};
  nodes = vector<ListNode*>(input.size(), nullptr);
  for (int i = 0; i < input.size(); ++i) {
    nodes[i] = new ListNode(input[i]);
  }
  for (int i = 0; i < input.size() - 1; ++i) {
    nodes[i]->next = nodes[i + 1];
  }
  output = solution.isPalindrome(nodes[0]);
  cout << ((output) ? "true\n" : "false\n");
  assert(output == true);

  input = {1, 2, 3, 4, 1};
  nodes = vector<ListNode*>(input.size(), nullptr);
  for (int i = 0; i < input.size(); ++i) {
    nodes[i] = new ListNode(input[i]);
  }
  for (int i = 0; i < input.size() - 1; ++i) {
    nodes[i]->next = nodes[i + 1];
  }
  output = solution.isPalindrome(nodes[0]);
  cout << ((output) ? "true\n" : "false\n");
  assert(output == false);

  cout << "Great success!" << '\n';
}
