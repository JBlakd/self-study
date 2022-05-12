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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        found_solution = false;
        int cur_sum = 0;
        dfs(root, cur_sum, targetSum);
        return found_solution;
    }

   private:
    bool found_solution;
    void dfs(TreeNode *cur_node, int &cur_sum, int &targetSum) {
        if (found_solution || cur_node == nullptr) {
            return;
        }

        cur_sum += cur_node->val;

        // Cannot do this. There's no telling whether the values are positive or negative.
        // // cur_sum exceeded, no point going further
        // if (cur_sum > targetSum) {
        //     // backtrack
        //     cur_sum -= cur_node->val;
        //     return;
        // }

        // root to LEAF
        if (cur_sum == targetSum) {
            // Is only a valid solution if cur_node is a leaf node
            if (cur_node->left == nullptr && cur_node->right == nullptr) {
                found_solution = true;
                return;
            }
            // either return with a valid solution, or no point going further
            // backtrack
        }

        dfs(cur_node->left, cur_sum, targetSum);
        dfs(cur_node->right, cur_sum, targetSum);
        // backtrack
        cur_sum -= cur_node->val;
    }
};

int main() {
    Solution solution;
    vector<TreeNode *> input;
    vector<int> node_vals;
    int targetSum;

    node_vals = {-2, -1, -3};
    targetSum = -5;
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
    cout << (solution.hasPathSum(input[0], targetSum) ? "true" : "false") << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    targetSum = 22;
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
    cout << (solution.hasPathSum(input[0], targetSum) ? "true" : "false") << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {1, 2};
    targetSum = 1;
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
    cout << (solution.hasPathSum(input[0], targetSum) ? "true" : "false") << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {-1};
    targetSum = 0;
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
    cout << (solution.hasPathSum(input[0], targetSum) ? "true" : "false") << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {3};
    targetSum = 3;
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
    cout << (solution.hasPathSum(input[0], targetSum) ? "true" : "false") << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {1, 2, 3};
    targetSum = 5;
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
    cout << (solution.hasPathSum(input[0], targetSum) ? "true" : "false") << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();
}
