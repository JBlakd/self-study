#include <iostream>
#include <queue>
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
    int maxDepth(TreeNode *root) {
        // base case
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    Solution solution;
    vector<TreeNode *> input;
    vector<int> node_vals;

    node_vals = {3, 9, 20, -1, -1, 15, 7};
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
    cout << solution.maxDepth(input[0]) << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {1, 2};
    // Node initialisation
    for (int val : node_vals) {
        TreeNode *cur_node = new TreeNode(val);
        input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (left_index < input.size()) {
            input[i]->left = input[left_index];
        }
        if (right_index < input.size()) {
            input[i]->right = input[right_index];
        }
    }
    cout << solution.maxDepth(input[0]) << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();
}
