#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *cur_node = q.front();
            q.pop();
            if (cur_node->left != nullptr) {
                q.push(cur_node->left);
            }
            if (cur_node->right != nullptr) {
                q.push(cur_node->right);
            }

            TreeNode *left_temp = cur_node->left;
            cur_node->left = cur_node->right;
            cur_node->right = left_temp;
        }

        return root;
    }
};

int main() {
    Solution solution;
}
