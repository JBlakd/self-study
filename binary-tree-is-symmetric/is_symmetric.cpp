#include <iostream>
#include <string>
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
    bool isSymmetric(TreeNode *root) {
        // base case. At the very least we need the root to have two identical children
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        if (root->left == nullptr && root->right != nullptr || root->right == nullptr && root->left != nullptr) {
            return false;
        }
        if (root->left->val != root->right->val) {
            return false;
        }

        found_asymmetric = false;
        // Lockstep explore left and right subtree
        dfs(root->left, root->right);
        return !found_asymmetric;
    }

   private:
    bool found_asymmetric;

    void dfs(TreeNode *p, TreeNode *q) {
        if (found_asymmetric || p == nullptr || q == nullptr) {
            return;
        }

        // Account for children's null status
        if ((p->left == nullptr && q->right != nullptr) || (q->right == nullptr && p->left != nullptr)) {
            found_asymmetric = true;
            return;
        }
        if ((p->right == nullptr && q->left != nullptr) || (q->left == nullptr && p->right != nullptr)) {
            found_asymmetric = true;
            return;
        }

        // At this point, no longer have to consider the validity of the null-ness of child nodes
        // Only need to consider the value correctness of the child nodes
        if (p->left != nullptr && p->left->val != q->right->val) {
            found_asymmetric = true;
            return;
        }
        if (p->right != nullptr && p->right->val != q->left->val) {
            found_asymmetric = true;
            return;
        }
        dfs(p->left, q->right);
        dfs(p->right, q->left);
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
    vector<TreeNode *> input;
    vector<int> node_vals;

    node_vals = {2, 3, 3, 4, 5, 5, 4, -1, -1, 8, 9, 9, 8};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
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
    cout << (solution.isSymmetric(input[0]) ? "symmetric" : "asymmetric") << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {2, 3, 3, 4, 5, 5};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
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
    cout << (solution.isSymmetric(input[0]) ? "symmetric" : "asymmetric") << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();
}
