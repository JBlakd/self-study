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
        // base case, only one element in current recursion
        // in other words, the begin and end iterators are the same
        if (in_begin == in_end) {
            TreeNode *cur_node = new TreeNode(*post_end);
            return cur_node;
        }

        // cur_node's value is the value of postorder at post_end,
        TreeNode *cur_node = new TreeNode(*post_end);
        // Left inorder starts at the beginning of inorder, and ends at the element left of the cur_node's value
        vector<int>::iterator &left_inorder_begin = inorder.begin();
        vector<int>::iterator &left_inorder_end = find(inorder.begin(), inorder.end(), *post_end) - 1;
        int left_num_elements = distance(left_inorder_begin, left_inorder_end) + 1;
        // Left postorder starts at the beginning of postorder, and goes on for the same length as left inorder
        cur_node->left = dfs(left_inorder_begin, left_inorder_end, inorder, postorder.begin(), postorder.begin() + left_num_elements - 1, postorder);
        // Right inorder starts at the element after cur_node's value, and ends at the end of inorder
        // Right postorder starts at postorder.begin() + left_num_elements, and ends at the element before post_end
        return cur_node;
    }
};

int main() {
    Solution solution;
}
