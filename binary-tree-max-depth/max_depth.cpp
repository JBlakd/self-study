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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode *> q;
        int depth = 1;

        q.push(root);
        while (!q.empty()) {
            // This loop is key to ensure we do all the nodes of each level before moving on to the next one
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode *cur_node = q.front();
                q.pop();

                if (cur_node->left != nullptr) {
                    q.push(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    q.push(cur_node->right);
                }
            }
            depth++;
        }

        return depth;
    }
};

int main() {
    Solution solution;
}
