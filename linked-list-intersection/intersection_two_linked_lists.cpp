#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;

        while (headA != nullptr) {
            visited.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr) {
            if (visited.find(headB) != visited.end()) {
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;
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
