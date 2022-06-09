#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
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
    int maxPathSum(TreeNode *root) {
        //                        <left_sum, right_sum>
        unordered_map<TreeNode *, pair<int, int>> hashmap;
        dfs(root, hashmap);

        int ret = numeric_limits<int>::min();
        for (auto &[cur_node, node_pair] : hashmap) {
            if (node_pair.first > 0 && node_pair.second > 0) {
                ret = max(ret, cur_node->val + node_pair.first + node_pair.second);
            } else if (node_pair.first > 0) {
                ret = max(ret, cur_node->val + node_pair.first);
            } else if (node_pair.second > 0) {
                ret = max(ret, cur_node->val + node_pair.second);
            } else {
                ret = max(ret, cur_node->val);
            }
        }

        return ret;
    }

   private:
    void dfs(TreeNode *cur_node, unordered_map<TreeNode *, pair<int, int>> &hashmap) {
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
            hashmap[cur_node] = {0, 0};
            return;
        }

        if (cur_node->left != nullptr) {
            dfs(cur_node->left, hashmap);
        }
        if (cur_node->right != nullptr) {
            dfs(cur_node->right, hashmap);
        }

        hashmap[cur_node] = {0, 0};
        if (cur_node->left != nullptr) {
            hashmap[cur_node].first = max(hashmap[cur_node->left].first + cur_node->left->val, hashmap[cur_node->left].second + cur_node->left->val);
            // See if not proceeding is more advantageous than proceeding
            hashmap[cur_node].first = max(hashmap[cur_node].first, 0);
        }
        if (cur_node->right != nullptr) {
            hashmap[cur_node].second = max(hashmap[cur_node->right].first + cur_node->right->val, hashmap[cur_node->right].second + cur_node->right->val);
            // See if not proceeding is more advantageous than proceeding
            hashmap[cur_node].second = max(hashmap[cur_node].second, 0);
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
