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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* ret = (list1->val <= list2->val) ? list1 : list2;
        ListNode* oth_list = (list1->val <= list2->val) ? list2 : list1;
        ListNode* cur_list = ret;

        while (cur_list != nullptr) {
            if (cur_list->next == nullptr) {
                // cur_list is exhausted, this means we can just append the other list to cur_list
                cur_list->next = oth_list;
                break;
            } else if (cur_list->next->val <= oth_list->val) {
                cur_list = cur_list->next;
            } else {
                // Save to-be-detached head
                ListNode* temp = cur_list->next;
                // Detach the head
                cur_list->next = oth_list;
                // cur_list becomes the other list
                cur_list = cur_list->next;
                // Assign oth_list to the now-detached head
                oth_list = temp;
            }
        }

        return ret;
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
}
