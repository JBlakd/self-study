#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        // Traverse big tree pre-order
        // For each big tree node visited, check identicality
        if (root == nullptr) {
            // If big tree is null, then only a null subRoot could be a subtree
            return (root == subRoot);
        }

        if (is_identical(root, subRoot)) {
            return true;
        }

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

   private:
    bool is_identical(TreeNode *a, TreeNode *b) {
        if (a == nullptr || b == nullptr) {
            return (a == nullptr && b == nullptr);
        }
        return (a->val == b->val) && is_identical(a->left, b->left) && is_identical(a->right, b->right);
    }
};

int main() {
    Solution solution;
    vector<TreeNode *> p_input;
    vector<int> p_node_vals;
    vector<TreeNode *> q_input;
    vector<int> q_node_vals;

    p_node_vals = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 2};
    // Node initialisation
    for (int val : p_node_vals) {
        if (val == -1) {
            p_input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
        p_input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < p_input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (p_input[i] == nullptr) {
            continue;
        }

        if (left_index < p_input.size()) {
            p_input[i]->left = p_input[left_index];
        }
        if (right_index < p_input.size()) {
            p_input[i]->right = p_input[right_index];
        }
    }
    q_node_vals = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 2};
    // Node initialisation
    for (int val : q_node_vals) {
        if (val == -1) {
            q_input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
        q_input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < q_input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (q_input[i] == nullptr) {
            continue;
        }

        if (left_index < q_input.size()) {
            q_input[i]->left = q_input[left_index];
        }
        if (right_index < q_input.size()) {
            q_input[i]->right = q_input[right_index];
        }
    }
    cout << solution.isSubtree(p_input[0], q_input[0]) << endl;
    for (auto node : p_input) {
        delete node;
    }
    for (auto node : q_input) {
        delete node;
    }
    p_input.clear();
    p_node_vals.clear();
    q_input.clear();
    q_node_vals.clear();

    p_node_vals = {1, 1};
    // Node initialisation
    for (int val : p_node_vals) {
        if (val == -1) {
            p_input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
        p_input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < p_input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (p_input[i] == nullptr) {
            continue;
        }

        if (left_index < p_input.size()) {
            p_input[i]->left = p_input[left_index];
        }
        if (right_index < p_input.size()) {
            p_input[i]->right = p_input[right_index];
        }
    }
    q_node_vals = {1};
    // Node initialisation
    for (int val : q_node_vals) {
        if (val == -1) {
            q_input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
        q_input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < q_input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (q_input[i] == nullptr) {
            continue;
        }

        if (left_index < q_input.size()) {
            q_input[i]->left = q_input[left_index];
        }
        if (right_index < q_input.size()) {
            q_input[i]->right = q_input[right_index];
        }
    }
    cout << solution.isSubtree(p_input[0], q_input[0]) << endl;
    for (auto node : p_input) {
        delete node;
    }
    for (auto node : q_input) {
        delete node;
    }
    p_input.clear();
    p_node_vals.clear();
    q_input.clear();
    q_node_vals.clear();
}
