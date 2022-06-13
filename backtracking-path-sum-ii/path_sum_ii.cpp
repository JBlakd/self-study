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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ret;
        int cur_sum = targetSum;
        vector<int> cur_vec;
        dfs(root, cur_sum, cur_vec, ret);
        return ret;
    }

   private:
    void dfs(TreeNode *cur_node, int &cur_sum, vector<int> &cur_vec, vector<vector<int>> &ret) {
        // base case: leaf reached
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
            cur_sum -= cur_node->val;
            cur_vec.emplace_back(cur_node->val);
            if (cur_sum == 0) {
                ret.emplace_back(cur_vec);
            }
            return;
        }

        cur_sum -= cur_node->val;
        cur_vec.emplace_back(cur_node->val);

        // Don't prune as vals and targetSum could be negative
        if (cur_node->left != nullptr) {
            dfs(cur_node->left, cur_sum, cur_vec, ret);
            // backtrack so that values are restored to current stack frame's valid state
            cur_sum += cur_node->left->val;
            cur_vec.pop_back();
        }
        if (cur_node->right != nullptr) {
            dfs(cur_node->right, cur_sum, cur_vec, ret);
            cur_sum += cur_node->right->val;
            cur_vec.pop_back();
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
    vector<TreeNode *> input;
    vector<int> node_vals;

    cout << "Great success!" << '\n';
}
