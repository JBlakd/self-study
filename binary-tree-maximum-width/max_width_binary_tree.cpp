#include <cassert>
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
    int widthOfBinaryTree(TreeNode *root) {
        // find first divergence
        while (!(root->left != nullptr && root->right != nullptr)) {
            if (root->left != nullptr) {
                root = root->left;
            } else if (root->right != nullptr) {
                root = root->right;
            } else {
                // leaf reached without finding divergence
                return 1;
            }
        }

        // simultaneous dfs of left and right branches
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int left_offset = -1;
        int right_offset = 1;
        int ret = 0;
        dfs(left, right, left_offset, right_offset, ret);
        return ret;
    }

   private:
    void dfs(TreeNode *left_node, TreeNode *right_node, int &left_offset, int &right_offset, int &ret) {
        ret = max(ret, right_offset - left_offset);

        if ((left_node->left == nullptr && left_node->right == nullptr) || (right_node->left == nullptr && right_node->right == nullptr)) {
            return;
        }

        if (left_node->left != nullptr && right_node->right != nullptr) {
            // Two optimal
            left_offset = 2 * left_offset;
            right_offset = 2 * right_offset;
            dfs(left_node->left, right_node->right, left_offset, right_offset, ret);
        } else if (left_node->right != nullptr && right_node->right != nullptr) {
            // One optimal
            left_offset = 2 * left_offset + 1;
            right_offset = 2 * right_offset;
            dfs(left_node->right, right_node->right, left_offset, right_offset, ret);
        } else if (left_node->left != nullptr && right_node->left != nullptr) {
            // One optimal
            left_offset = 2 * left_offset;
            right_offset = 2 * right_offset - 1;
            dfs(left_node->left, right_node->left, left_offset, right_offset, ret);
        } else {
            // None optimal
            left_offset = 2 * left_offset + 1;
            right_offset = 2 * right_offset - 1;
            dfs(left_node->right, right_node->left, left_offset, right_offset, ret);
        }
    }
};

template <typename T>
void print_vector(vector<T> vec) {
    cout << "{";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}";
}

int main() {
    Solution solution;

    /* UNIT TESTS HERE */
    // [1,1,1,1,1,1,1,null,null,null,1,null,null,null,null,2,2,2,2,2,2,2,null,2,null,null,2,null,2]

    cout << "Great success!" << '\n';
}
