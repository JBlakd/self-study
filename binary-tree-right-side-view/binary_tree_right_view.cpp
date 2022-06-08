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
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        // For each level, find the right-most node
        vector<int> ret;

        dfs(root, 0, ret);

        return ret;
    }

   private:
    void dfs(TreeNode *cur_node, int cur_depth, vector<int> &ret) {
        if (cur_depth == ret.size()) {
            ret.emplace_back(cur_node->val);
        }

        if (cur_node->right != nullptr) {
            dfs(cur_node->right, cur_depth + 1, ret);
        }
        if (cur_node->left != nullptr) {
            dfs(cur_node->left, cur_depth + 1, ret);
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
}
