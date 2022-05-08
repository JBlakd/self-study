#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
   public:
    NestedIterator(vector<NestedInteger> &nestedList) : nested_list(&nestedList), cur_nested_int(&(nested_list->at(0))), bottom_level_size(nestedList.size()) {
        frame_stack = {};
        // Means the iterator is before index 0
        frame_stack.emplace(-1, &nestedList);
        stack_bottom_pointer = &frame_stack.top();
        cout << "emplaced: -1, stack level: " << frame_stack.size() - 1 << endl;
    }

    int next() {
        // We assume next() only gets called when hasNext() is true

        // If we are on the last element of the current list, pop
        if (frame_stack.top().first == frame_stack.top().second->size() - 1) {
            cout << "popped: " << frame_stack.top().first << ", old stack level: " << frame_stack.size() - 1;
            frame_stack.pop();
            cout << ", new stack level: " << frame_stack.size() - 1 << endl;
        }
        ++frame_stack.top().first;
        cout << "incremented: " << frame_stack.top().first << ", stack level: " << frame_stack.size() - 1 << endl;        

        cur_nested_int = &(frame_stack.top().second->at(frame_stack.top().first));
        if (cur_nested_int->isInteger()) {
            cout << "cur_nested_int is: " << cur_nested_int->getInteger() << endl;
        } else {
            cout << "cur_nested_int is: an array with size "  << cur_nested_int->getList().size() <<endl;
        }

        while (!(cur_nested_int->isInteger())) {
            std::vector<NestedInteger> *cur_nested_list = (std::vector<NestedInteger> *)&(cur_nested_int->getList());
            frame_stack.emplace(0, cur_nested_list);
            cout << "emplaced: " << frame_stack.top().first << ", stack level: " << frame_stack.size() - 1 << endl;
            cur_nested_int = &(frame_stack.top().second->at(frame_stack.top().first));
        }

        cout << "returned: " << cur_nested_int->getInteger() << ", stack level: " << frame_stack.size() - 1 << endl;
        return cur_nested_int->getInteger();
    }

    bool hasNext() {
        // False if: stack is size 1 meaning we're at the bottom level, and the index is bottom_level_size - 1
        if (stack_bottom_pointer->first == bottom_level_size - 1 && frame_stack.top().first == frame_stack.top().second->size() - 1) {
            return false;
        }

        // if (!nested_list->at(0).isInteger() && nested_list->at(0).getList().empty()) {
        //     return false;
        // }

        // All other cases, has next. (really no edge-cases?)
        return true;
    }

   private:
    stack<pair<int, vector<NestedInteger> *>> frame_stack;
    pair<int, vector<NestedInteger> *>* stack_bottom_pointer;
    int bottom_level_size;
    vector<NestedInteger> *nested_list;
    NestedInteger *cur_nested_int;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

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
}
