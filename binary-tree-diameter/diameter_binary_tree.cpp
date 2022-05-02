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
    int diameterOfBinaryTree(TreeNode *root) {
        diameter_champion = 0;
        find_height(root);
        return diameter_champion;
    }

   private:
    int diameter_champion = 0;
    // helper functions which calculates the diameter of cur_node's subtree
    int find_height(TreeNode *cur_node) {
        // THE LONGEST PATH MAY OR MAY NOT PASS THROUGH THE ROOT
        if (cur_node == nullptr) {
            return 0;
        }

        int left_height = find_height(cur_node->left);
        int right_height = find_height(cur_node->right);
        int diameter = left_height + right_height;

        if (diameter > diameter_champion) {
            diameter_champion = diameter;
        }
        // cout << "Node " << cur_node->val << " left_height: " << left_height;
        // cout << ". Node " << cur_node->val << " right_height: " << right_height << endl;
        return max(left_height, right_height) + 1;
    }
};

int main() {
    Solution solution;
    vector<TreeNode *> input;
    vector<int> node_vals;
    //           .  .     .             .                             .
    node_vals = {1, 2, 3, 4, 5, -1, -1, 6, -1, -1, 7, -1, -1, -1, -1, 8, -1, -1, -1, -1, -1, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1};
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
    cout << solution.diameterOfBinaryTree(input[0]) << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

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
    cout << solution.diameterOfBinaryTree(input[0]) << endl;
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
    cout << solution.diameterOfBinaryTree(input[0]) << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();
}
