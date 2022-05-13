#include <algorithm>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root = dfs(inorder.begin(), inorder.end() - 1, inorder, postorder.begin(), postorder.end() - 1, postorder);
        return root;
    }

   private:
    TreeNode *dfs(vector<int>::iterator in_begin, vector<int>::iterator in_end, vector<int> &inorder, vector<int>::iterator post_begin, vector<int>::iterator post_end, vector<int> &postorder) {
        // No need for null node testcase because we will check for validity before recursing

        // base case, only one element in current recursion
        // in other words, the begin and end iterators are the same
        if (in_begin == in_end) {
            TreeNode *cur_node = new TreeNode(*post_end);
            return cur_node;
        }

        // cur_node's value is the value of postorder at post_end,
        TreeNode *cur_node = new TreeNode(*post_end);
        vector<int>::iterator inorder_cur_location = find(inorder.begin(), inorder.end(), cur_node->val);
        int num_left_subtree_nodes = distance(in_begin, inorder_cur_location);
        int num_right_subtree_nodes = distance(inorder_cur_location, in_end);
        // check if left node exists before recursing
        if (inorder_cur_location != in_begin) {
            cur_node->left = dfs(in_begin, in_begin + num_left_subtree_nodes - 1, inorder, post_end - num_right_subtree_nodes - num_left_subtree_nodes, post_end - num_right_subtree_nodes - 1, postorder);
        }
        // check if right node exists before recursing
        if (inorder_cur_location != in_end) {
            cur_node->right = dfs(inorder_cur_location + 1, inorder_cur_location + num_right_subtree_nodes, inorder, post_end - num_right_subtree_nodes, post_end - 1, postorder);
        }
        return cur_node;
    }
};

int main() {
    Solution solution;
    vector<int> inorder;
    vector<int> postorder;
    TreeNode *output;

    inorder = {3, 2, 1};
    postorder = {3, 2, 1};
    output = solution.buildTree(inorder, postorder);
    cout << output->val << endl;

    inorder = {1};
    postorder = {1};
    output = solution.buildTree(inorder, postorder);
    cout << output->val << endl;

    inorder = {1, 2};
    postorder = {2, 1};
    output = solution.buildTree(inorder, postorder);
    cout << output->val << endl;

    inorder = {2, 1};
    postorder = {2, 1};
    output = solution.buildTree(inorder, postorder);
    cout << output->val << endl;

    inorder = {9, 3, 15, 20, 7};
    postorder = {9, 15, 7, 20, 3};
    output = solution.buildTree(inorder, postorder);
    cout << output->val << endl;

    inorder = {5, 4, 6, 3, 8, 7};
    postorder = {5, 6, 4, 8, 7, 3};
    output = solution.buildTree(inorder, postorder);
    cout << output->val << endl;
}
