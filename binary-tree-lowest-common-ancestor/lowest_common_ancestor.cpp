#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case. Encountered either p or q during postorder traversal. Do not recurse any deeper.
        if (root == p || root == q) {
            return root;
        }

        // postorder traversal
        TreeNode* left_search_result = nullptr;
        TreeNode* right_search_result = nullptr;
        if (root->left != nullptr) {
            left_search_result = lowestCommonAncestor(root->left, p, q);
        }
        if (root->right != nullptr) {
            right_search_result = lowestCommonAncestor(root->right, p, q);
        }

        // At this point, the entire subtree at the current root node has been traversed, because postorder traversal, baby!
        if (left_search_result != nullptr && right_search_result != nullptr) {
            // Answer found if both left and right search results have been found
            // If we reach this case at a subtree root, the full recursion will still only finish once we have have returned from the root
            // When we finally recurse back to the root, it will return either left_search_result or right_search_result, corresponding to the side of the root in which the answer lies
            return root;
        } else if (left_search_result != nullptr) {
            // If only the left result has been found, float the left result upward
            return left_search_result;
        } else if (right_search_result != nullptr) {
            // If only the right result has been found, float the right result upward
            return right_search_result;
        }
        // no results found
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
    vector<TreeNode*> input;
    vector<int> node_vals;
    TreeNode* p;
    TreeNode* q;

    // p = 4, q = 5, ans = 3
    node_vals = {1, 2, 3, -1, -1, 4, 5};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode* cur_node = new TreeNode(val);
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
    p = input[5];
    q = input[6];
    cout << solution.lowestCommonAncestor(input[0], p, q)->val << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    // p = 5, q = 6, ans = 4
    node_vals = {3, 4, 9, 5, 6, -1, -1, 7, 8, 10, 11};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode* cur_node = new TreeNode(val);
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
    p = input[3];
    q = input[4];
    cout << solution.lowestCommonAncestor(input[0], p, q)->val << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    // p = 5, q = 9, ans = 3
    node_vals = {3, 4, 9, 5, 6, -1, -1, 7, 8, 10, 11};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode* cur_node = new TreeNode(val);
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
    p = input[3];
    q = input[2];
    cout << solution.lowestCommonAncestor(input[0], p, q)->val << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    // p = 11, q = 4, ans = 4
    node_vals = {3, 4, 9, 5, 6, -1, -1, 7, 8, 10, 11};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode* cur_node = new TreeNode(val);
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
    p = input[10];
    q = input[1];
    cout << solution.lowestCommonAncestor(input[0], p, q)->val << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();
}
