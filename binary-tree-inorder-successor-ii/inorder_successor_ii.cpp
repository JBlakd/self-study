#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
   public:
    Node* inorderSuccessor(Node* node) {
        if (node->right == nullptr) {
            // iterate through parents
            // return the first ancestor we encounter that the previously-iterated node is a left child
            while (node != nullptr) {
                Node* prev = node;
                node = node->parent;
                if (node == nullptr || node->left == prev) {
                    break;
                }
            }

            return node;
        } else {
            // starting from right child, keep iterating through the left child
            // And return the first left-childless node encountered
            node = node->right;
            while (node->left != nullptr) {
                node = node->left;
            }

            return node;
        }
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
