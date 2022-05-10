#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Don't fucking implement your own doubly-linked list ya dumb kunt
class LRUCache {
   public:
    LRUCache(int capacity) : capacity(capacity) {
    }

    int get(int key) {
        // Move to front if key exists
        if (hashmap.find(key) != hashmap.end()) {
            auto found_node(hashmap.at(key));
            // Move to front
            linked_list.splice(linked_list.begin(), linked_list, found_node);
            return found_node->second;
        }

        return -1;
    }

    void put(int key, int value) {
        // Update if key exists
        if (hashmap.find(key) != hashmap.end()) {
            auto found_node(hashmap.at(key));
            // Update
            found_node->second = value;
            // Move to front
            linked_list.splice(linked_list.begin(), linked_list, found_node);
            return;
        }

        // Key doesn't exist, capacity not yet reached
        if (hashmap.size() < capacity) {
            // Add new node to front
            linked_list.emplace_front(key, value);
            // Add hashmap entry
            hashmap.emplace(key, linked_list.begin());
        } else {
            // Capacity reached
            // Remove tail
            auto old_tail_key = linked_list.back().first;
            linked_list.pop_back();
            hashmap.erase(old_tail_key);

            // Add new node to front
            linked_list.emplace_front(key, value);
            // Add hashmap entry
            hashmap.emplace(key, linked_list.begin());
        }
    }

   private:
    //            key, pointer (iterator) to node
    unordered_map<int, list<pair<int, int>>::iterator> hashmap;
    //   node key, val
    list<pair<int, int>> linked_list;
    int capacity;
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
