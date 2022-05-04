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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ret;
        vector<int> temp;

        queue<TreeNode *> todo;
        todo.push(root);
        int current_level_width = 1;
        int next_level_width = 0;

        while (!todo.empty()) {
            TreeNode *cur_node = todo.front();
            todo.pop();
            temp.push_back(cur_node->val);

            if (cur_node->left != nullptr) {
                todo.push(cur_node->left);
                ++next_level_width;
            }
            if (cur_node->right != nullptr) {
                todo.push(cur_node->right);
                ++next_level_width;
            }

            if (temp.size() == current_level_width) {
                // level done
                ret.push_back(temp);
                current_level_width = next_level_width;
                next_level_width = 0;
                temp.clear();
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<TreeNode *> input;
    vector<int> node_vals;

    node_vals = {1, 2, 3, 4, -1, -1, 5, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, 7};
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
    solution.levelOrder(input[0]);
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
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
    solution.levelOrder(input[0]);
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();
}
