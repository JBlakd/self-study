#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
   public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {
        // If I just have a linked list without a hashmap, then I couldn't get the nodes in the middle of the list in O(1)
        // If I don't have a linked list, then I couldn't really keep track of the age order of the nodes
        // Need a doubly-linked list in order to transplant middle nodes (re-linking prev and next) to the head
        hashmap.clear();
    }

    // Return -1 if not found
    int get(int key) {
        if (hashmap.find(key) == hashmap.end()) {
            return -1;
        }

        // re-link everything
        ListNode* found_node = hashmap.at(key);
        if (found_node == head) {
            return found_node->val;
        }

        if (found_node == tail) {
            tail = found_node->next;
            tail->prev = nullptr;
            // Special case for if the new tail is the head
            // In this case, new tail needs to have a next
            if (tail == head) {
                tail->next = found_node;
            }
            found_node->next = nullptr;
            found_node->prev = head;
            head = found_node;
            return found_node->val;
        }

        // Now we are sure that found_node is a middle node
        found_node->prev->next = found_node->next;
        found_node->next->prev = found_node->prev;

        // reassign node as head
        found_node->next = nullptr;
        found_node->prev = head;
        head = found_node;
        return found_node->val;
    }

    void put(int key, int value) {
        if (capacity == 1) {
            if (hashmap.size() == 1) {
                hashmap.erase(head->key);
                delete head;
            }
            head = new ListNode(key, value);
            tail = head;
            hashmap.emplace(key, head);
            return;
        }

        // if key already exists, then update
        if (hashmap.find(key) != hashmap.end()) {
            ListNode* found_node = hashmap.at(key);
            found_node->val = value;
            if (found_node == head) {
                return;
            }

            if (found_node == tail) {
                tail = found_node->next;
                tail->prev = nullptr;
                // Special case for if the new tail is the head
                // In this case, new tail needs to have a next
                if (tail == head) {
                    tail->next = found_node;
                }
                found_node->next = nullptr;
                found_node->prev = head;
                head = found_node;
                return;
            }

            // Now we are sure that found_node is a middle node
            found_node->prev->next = found_node->next;
            found_node->next->prev = found_node->prev;

            // reassign node as head
            found_node->next = nullptr;
            found_node->prev = head;
            head = found_node;

            return;
        }

        if (hashmap.size() >= capacity) {
            // delete the tail, re-assign tail
            ListNode* old_tail = tail;
            tail = old_tail->next;
            tail->prev = nullptr;
            hashmap.erase(old_tail->key);
            delete old_tail;
        }

        // create a new node and assign it to the head
        ListNode* new_head = new ListNode(key, value);
        if (hashmap.size() > 0) {
            new_head->prev = head;
            head->next = new_head;
        }
        if (hashmap.size() == 0) {
            tail = new_head;
        }
        head = new_head;
        hashmap.emplace(key, head);
    }

   private:
    // head of list denotes most recently used. Useful for assigning to most recently get() or put() elements
    // tail of list denotes least recently used. Useful for getting the next element for deletion in O(1) time.
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    };

    int capacity;
    unordered_map<int, ListNode*> hashmap;
    ListNode* head;
    ListNode* tail;

    // ~LRUCache() {
    //     ListNode* cur_node = tail;
    //     while (cur_node != nullptr) {
    //         ListNode* next_node = cur_node->next;
    //         delete cur_node;
    //         cur_node = next_node;
    //     }
    // }
};

int main() {
    LRUCache* solution;

    solution = new LRUCache(2);
    solution->put(2, 1);               // {{2,1}}
    solution->put(1, 1);               // {{2,1}, {1,1}}
    solution->put(2, 3);               // {{1,1}, {2,3}}
    solution->put(4, 1);               // {{2,3}, {4,1}}
    cout << solution->get(1) << endl;  // -1
    cout << solution->get(2) << endl;  // 3
    cout << endl;

    solution = new LRUCache(2);
    cout << solution->get(2) << endl;  // -1
    solution->put(2, 6);               // {{2,6}}
    cout << solution->get(1) << endl;  // -1
    solution->put(1, 5);               // {{2,6}, {1,5}}
    solution->put(1, 2);               // {{2,6}, {1,2}}
    cout << solution->get(1) << endl;  // 2
    cout << solution->get(2) << endl;  // 6
    cout << endl;

    solution = new LRUCache(2);
    solution->put(2, 1);               // {{2,1}}
    solution->put(2, 2);               // {{2,2}}
    cout << solution->get(2) << endl;  // 2
    solution->put(1, 1);               // {{2,2}, {1,1}}
    solution->put(4, 1);               // {{1,1}, {4,1}}
    cout << solution->get(2) << endl;  // -1
    cout << endl;

    solution = new LRUCache(1);
    solution->put(2, 1);               // cache is {1=100}
    cout << solution->get(2) << endl;  // return 1
    solution->put(3, 2);               // cache is {1=100, 2=200}
    cout << solution->get(2) << endl;  // return -1
    cout << solution->get(3) << endl;  // return 2
    cout << endl;

    solution = new LRUCache(2);
    solution->put(1, 100);             // cache is {1=100}
    solution->put(2, 200);             // cache is {1=100, 2=200}
    cout << solution->get(1) << endl;  // return 100
    solution->put(3, 300);             // LRU key was 2, evicts key 2, cache is {1=100, 3=300}
    cout << solution->get(2) << endl;  // returns -1 (not found)
    solution->put(4, 400);             // LRU key was 1, evicts key 1, cache is {4=400, 3=300}
    cout << solution->get(1) << endl;  // return -1 (not found)
    cout << solution->get(3) << endl;  // return 300
    cout << solution->get(4) << endl;  // return 400
    cout << endl;
}
