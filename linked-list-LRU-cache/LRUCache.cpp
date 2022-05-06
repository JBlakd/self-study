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
        // reassign node as head

        // re-link everything
    }

    void put(int key, int value) {
        if (hashmap.size() >= capacity) {
            // delete the tail

            // re-assign tail

            // create a new node and assign it to the head
        } else {
            // create a new node and assign it to the head,
        }
    }

   private:
    // head of list denotes most recently used. Useful for assigning to most recently get() or put() elements
    // tail of list denotes least recently used. Useful for getting the next element for deletion in O(1) time.
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int x, LRUCache* parent_cache) : val(x), next(nullptr), prev(nullptr) {}
    };

    int capacity;
    unordered_map<int, int> hashmap;
    ListNode* head;
    ListNode* tail;

    ~LRUCache() {
        ListNode* cur_node = head;
        while (cur_node != nullptr) {
            ListNode* next_node = cur_node->next;
            delete cur_node;
            cur_node = next_node;
        }
    }
};

int main() {
    LRUCache* solution = new LRUCache(2);
    solution->put(1, 1);  // cache is {1=1}
    solution->put(2, 2);  // cache is {1=1, 2=2}
    solution->get(1);     // return 1
    solution->put(3, 3);  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    solution->get(2);     // returns -1 (not found)
    solution->put(4, 4);  // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    solution->get(1);     // return -1 (not found)
    solution->get(3);     // return 3
    solution->get(4);     // return 4
}
