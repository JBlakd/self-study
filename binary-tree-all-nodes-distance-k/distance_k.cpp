#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // DFS entire tree, convert it to an undirected graph
        unordered_map<TreeNode*, unordered_set<TreeNode*>> adj_list;
        dfs(root, adj_list);

        // dfs from target
        vector<int> ret;
        int cur_depth = 0;
        dfs_k(target, cur_depth, adj_list, ret, k);

        return ret;
    }

   private:
    void dfs_k(TreeNode* cur_node, int& cur_depth, unordered_map<TreeNode*, unordered_set<TreeNode*>>& adj_list, vector<int>& ret, int& k) {
        if (cur_depth == k) {
            ret.emplace_back(cur_node->val);
            return;
        }

        for (auto& nei : adj_list[cur_node]) {
            // burn the bridge (so we don't have to maintain a "visited" set)
            adj_list[nei].erase(cur_node);
            ++cur_depth;
            dfs_k(nei, cur_depth, adj_list, ret, k);
            // backtrack
            --cur_depth;
        }
    }

    void dfs(TreeNode* cur_node, unordered_map<TreeNode*, unordered_set<TreeNode*>>& adj_list) {
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
            return;
        }

        if (cur_node->left != nullptr) {
            adj_list[cur_node].emplace(cur_node->left);
            adj_list[cur_node->left].emplace(cur_node);
            dfs(cur_node->left, adj_list);
        }
        if (cur_node->right != nullptr) {
            adj_list[cur_node].emplace(cur_node->right);
            adj_list[cur_node->right].emplace(cur_node);
            dfs(cur_node->right, adj_list);
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

    cout << "Great success!" << '\n';
}
