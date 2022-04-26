#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // choose the path where both nodes are in the same subtree

        while (true) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
                continue;
            }

            if (p->val > root->val && q->val > root->val) {
                root = root->right;
                continue;
            }
            return root;
        }
    }
};

int main() {
    Solution solution;
}
