#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            // cout << "null input" << endl
            //      << endl;
            return nullptr;
        }

        vector<pair<Node*, int>> level_order_vec;

        queue<pair<Node*, int>> todo;
        todo.emplace(root, 0);

        while (!todo.empty()) {
            pair<Node*, int> cur_node = todo.front();
            todo.pop();
            level_order_vec.push_back(cur_node);
            // cout << "Level: " << cur_node.second << " Node val: " << cur_node.first->val << endl;

            if (cur_node.first->left != nullptr) {
                todo.emplace(cur_node.first->left, cur_node.second + 1);
            }
            if (cur_node.first->right != nullptr) {
                todo.emplace(cur_node.first->right, cur_node.second + 1);
            }
        }

        // Loop from the second element to the penultimate element
        for (int i = 1; i < level_order_vec.size() - 1; ++i) {
            if (level_order_vec[i].second == level_order_vec[i + 1].second) {
                level_order_vec[i].first->next = level_order_vec[i + 1].first;
            }
        }

        // for (auto cur_node : level_order_vec) {
        //     cout << "Level: " << cur_node.second << " Node val: " << cur_node.first->val << " Next: ";
        //     if (cur_node.first->next == nullptr) {
        //         cout << "null";
        //     } else {
        //         cout << cur_node.first->next->val;
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        return root;
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
    vector<Node*> input;
    vector<int> node_vals;
    Node* output;

    node_vals = {-1};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        Node* cur_node = new Node(val);
        input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (input[i] == nullptr) {
            continue;
        }

        if (left_index < input.size()) {
            input[i]->left = input[left_index];
        }
        if (right_index < input.size()) {
            input[i]->right = input[right_index];
        }
    }
    output = solution.connect(input[0]);
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {7};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        Node* cur_node = new Node(val);
        input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (input[i] == nullptr) {
            continue;
        }

        if (left_index < input.size()) {
            input[i]->left = input[left_index];
        }
        if (right_index < input.size()) {
            input[i]->right = input[right_index];
        }
    }
    output = solution.connect(input[0]);
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {1, 2, 3, 4, 5, -1, 7};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        Node* cur_node = new Node(val);
        input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (input[i] == nullptr) {
            continue;
        }

        if (left_index < input.size()) {
            input[i]->left = input[left_index];
        }
        if (right_index < input.size()) {
            input[i]->right = input[right_index];
        }
    }
    output = solution.connect(input[0]);
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();
}
