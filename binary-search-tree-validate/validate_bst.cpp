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
    bool isValidBST(TreeNode *root) {
        return is_valid_helper(root, (1 << 31), ~(1 << 31));
    }

   private:
    bool is_valid_helper(TreeNode *cur_node, int lower_bound, int upper_bound) {
        // we manage to reach a null node without running into problems
        // so we can cascade validity upwards
        if (cur_node == nullptr) {
            return true;
        }

        // Edge cases
        if (root->val == ~(1 << 31)) {
            if (root->right != nullptr) {
                return false;
            }
            return true;
        }

        if (root->val == (1 << 31)) {
            if (root->left != nullptr) {
                return false;
            }
            return true;
        }

        if (cur_node->val <= lower_bound || cur_node->val >= upper_bound) {
            return false;
        }

        return (is_valid_helper(cur_node->left, lower_bound, cur_node->val) && is_valid_helper(cur_node->right, cur_node->val, upper_bound));
    }
};

int main() {
    Solution solution;
}
