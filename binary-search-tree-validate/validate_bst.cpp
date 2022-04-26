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
    // using in-order traversal to validate if traversed is, well, in-order
    bool isValidBST(TreeNode *root) {
        TreeNode *prev = nullptr;
        return is_valid_helper(root, prev);
    }

   private:
    bool is_valid_helper(TreeNode *cur_node, TreeNode *&prev) {
        if (cur_node == nullptr) {
            return true;
        }

        if (!is_valid_helper(cur_node->left, prev)) {
            return false;
        }
        if (prev != nullptr && prev->val >= cur_node->val) {
            return false;
        }
        prev = cur_node;
        return is_valid_helper(cur_node->right, prev);
    }
};

int main() {
    Solution solution;
}
