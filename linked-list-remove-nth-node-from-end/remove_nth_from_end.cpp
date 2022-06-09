#include <iostream>
#include <queue>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            return nullptr;
        }

        queue<ListNode*> q;
        ListNode* cur_node = head;

        int count = 0;
        while (cur_node != nullptr) {
            q.emplace(cur_node);
            if (q.size() > n + 1) {
                q.pop();
            }
            cur_node = cur_node->next;
            ++count;
        }
        if (n == count) {
            ListNode* prev_head = head;
            head = head->next;
            prev_head->next = nullptr;
            return head;
        }

        ListNode* prev = q.front();
        q.pop();
        if (q.empty()) {
            prev->next = nullptr;
        } else {
            prev->next = q.front()->next;
            q.front()->next = nullptr;
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
}
