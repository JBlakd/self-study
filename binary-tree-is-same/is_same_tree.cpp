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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        is_same_tree = true;
        dfs(p, q);
        return is_same_tree;
    }

   private:
    bool is_same_tree;

    void dfs(TreeNode *cur_p, TreeNode *cur_q) {
        if (!is_same_tree) {
            return;
        }

        if (cur_p == nullptr && cur_q == nullptr) {
            return;
        }

        if ((cur_p == nullptr && cur_q != nullptr) || (cur_p != nullptr && cur_q == nullptr)) {
            is_same_tree = false;
            return;
        }

        if (cur_p->val != cur_q->val) {
            is_same_tree = false;
            return;
        }

        dfs(cur_p->right, cur_q->right);
        dfs(cur_p->left, cur_q->left);
    }
};

int main() {
    Solution solution;
    vector<TreeNode *> p_input;
    vector<int> p_node_vals;
    vector<TreeNode *> q_input;
    vector<int> q_node_vals;

    p_node_vals = {1, 2, 3};
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
    q_node_vals = {1, 2, 3};
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
    cout << solution.isSameTree(p_input[0], q_input[0]) << endl;
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

    p_node_vals = {1, 2};
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
    q_node_vals = {1, -1, 2};
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
    cout << solution.isSameTree(p_input[0], q_input[0]) << endl;
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

    p_node_vals = {1, 2, 1};
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
    q_node_vals = {1, 1, 2};
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
    cout << solution.isSameTree(p_input[0], q_input[0]) << endl;
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
