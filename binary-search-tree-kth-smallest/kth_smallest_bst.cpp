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
    int kthSmallest(TreeNode *root, int k) {
        inorder(root, k);
        return result;
    }

   private:
    int result = -1;

    void inorder(TreeNode *cur_node, int& count) {
        if (cur_node->left != nullptr) {
            inorder(cur_node->left, count);
        }
        count--;
        if (count == 0) {
            result = cur_node->val;
            return;
        }
        if (cur_node->right != nullptr) {
            inorder(cur_node->right, count);
        }
    }
};

int main() {
    Solution solution;
}
