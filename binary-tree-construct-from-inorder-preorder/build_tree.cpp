#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = dfs(0, preorder.size() - 1, preorder, 0, inorder.size() - 1, inorder);
        return root;
    }

   private:
    TreeNode* dfs(int pre_start, int pre_end, vector<int>& preorder, int in_start, int in_end, vector<int>& inorder) {
        TreeNode* cur_node = new TreeNode(preorder[pre_start]);

        // Base case: leaf reached
        if (pre_start == pre_end) {
            return cur_node;
        }

        // Find index of cur_node value within inorder array
        int in_cur_idx;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == preorder[pre_start]) {
                in_cur_idx = i;
            }
        }

        // left next inorder: [in_start, in_cur_idx - 1]
        // num_left_elements = in_cur_idx - in_start
        // num_right_elements = in_end - in_cur_index
        // right next inorder: [in_cur_idx + 1, in_end]
        // left next preorder: [pre_start + 1, pre_start + num_left_elements]
        // right next preorder: [pre_end - num_right_elements + 1 , pre_end]

        int num_left_elements = in_cur_idx - in_start;
        int num_right_elements = in_end - in_cur_idx;

        // dfs left if left child exists
        if (in_cur_idx != in_start) {
            cur_node->left = dfs(pre_start + 1, pre_start + num_left_elements, preorder, in_start, in_cur_idx - 1, inorder);
        }

        // dfs right if right child exists
        if (in_cur_idx != in_end) {
            cur_node->right = dfs(pre_end - num_right_elements + 1, pre_end, preorder, in_cur_idx + 1, in_end, inorder);
        }

        return cur_node;
    }
};

int main() {
    Solution solution;
    vector<int> inorder;
    vector<int> preorder;
    TreeNode* output;

    inorder = {6, 9, 7, 2, 1, 4, 2};
    preorder = {9, 2, 7, 1, 6, 2, 4};
    output = solution.buildTree(inorder, preorder);
    cout << output->val << endl;

    // inorder = {1};
    // postorder = {1};
    // output = solution.buildTree(inorder, postorder);
    // cout << output->val << endl;

    // inorder = {1, 2};
    // postorder = {2, 1};
    // output = solution.buildTree(inorder, postorder);
    // cout << output->val << endl;

    // inorder = {2, 1};
    // postorder = {2, 1};
    // output = solution.buildTree(inorder, postorder);
    // cout << output->val << endl;

    // inorder = {9, 3, 15, 20, 7};
    // postorder = {9, 15, 7, 20, 3};
    // output = solution.buildTree(inorder, postorder);
    // cout << output->val << endl;

    // inorder = {5, 4, 6, 3, 8, 7};
    // postorder = {5, 6, 4, 8, 7, 3};
    // output = solution.buildTree(inorder, postorder);
    // cout << output->val << endl;
}
