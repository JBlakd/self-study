#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // the successor is either the right child,
        // or the parent if the child is the left child of the parent
        TreeNode* ret = nullptr;
        dfs(root, nullptr, p, ret);
        return ret;
    }

   private:
    void dfs(TreeNode* cur_node, TreeNode* parent, TreeNode*& p, TreeNode*& result) {
        if (result != nullptr) {
            return;
        }

        if (cur_node == p) {
            // the successor is either the right child's left-most child
            // or the parent if the child is the left child of the parent
            if (cur_node->right != nullptr) {
                get_next_left_childless(cur_node->right, result);
                return;
            } else {
                result = parent;
                return;
            }
        }

        if (p->val < cur_node->val) {
            // visit left child, passing cur_node as the child's parent
            dfs(cur_node->left, cur_node, p, result);
        } else {
            // visit right child, disowning the child (the child's parent will be cur_node's parents)
            dfs(cur_node->right, parent, p, result);
        }
    }

    void get_next_left_childless(TreeNode* cur_node, TreeNode*& result) {
        if (cur_node->left == nullptr) {
            result = cur_node;
            return;
        }

        get_next_left_childless(cur_node->left, result);
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

    cout << "Great success!" << '\n';
}
