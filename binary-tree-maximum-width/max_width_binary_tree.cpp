#include <algorithm>
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
        int cur_depth = 0;
        int cur_id = 1;
        vector<pair<int, int>> depth_ids;
        dfs(root, cur_depth, cur_id, depth_ids);

        return -1;
    }

   private:
    void dfs(TreeNode *cur_node, int &cur_depth, int &cur_id, vector<pair<int, int>> &depth_ids) {
        if (cur_depth >= depth_ids.size()) {
            depth_ids.emplace_back(cur_id, cur_id);
        } else {
            auto &[left, right] = depth_ids[cur_depth];
            left = min(left, cur_id);
            right = max(right, cur_id);
        }

        if (cur_node->left == nullptr && cur_node->right == nullptr) {
            cout << "depth: " << cur_depth << " id: " << cur_id << '\n';
        }

        if (cur_node->left != nullptr) {
            ++cur_depth;
            cur_id *= 2;
            dfs(cur_node->left, cur_depth, cur_id, depth_ids);
            // backtrack
            --cur_depth;
            cur_id /= 2;
        }
        if (cur_node->right != nullptr) {
            ++cur_depth;
            cur_id = 2 * cur_id + 1;
            dfs(cur_node->right, cur_depth, cur_id, depth_ids);
            --cur_depth;
            cur_id = (cur_id - 1) / 2;
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
