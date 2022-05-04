#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            return head;
        } else if (head->next->next == nullptr) {
            ListNode* ret = head->next;
            ret->next = head;
            head->next = nullptr;
        }

        // iterative solution
        ListNode* prev_node = head;
        ListNode* cur_node = head->next;
        ListNode* next_node = cur_node->next;
        head->next = nullptr;
        while (cur_node->next != nullptr) {
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
            next_node = cur_node->next;
        }
        cur_node->next = prev_node;

        // Return the head of the reversed list
        return cur_node;
    }
};

int main() {
    Solution solution;
    ListNode* output_head;

    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    output_head = solution.reverseList(&n1);
    while (output_head != nullptr) {
        cout << output_head->val << ", ";
        output_head = output_head->next;
    }
    cout << endl;
}
