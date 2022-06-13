#include <cassert>
#include <iostream>
#include <list>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        // dfs, use a double-ended list on alternate levels to achieve zigzag
        // when converting lists to vectors, make use to use move semantics

        vector<list<int>> lists;
        int cur_depth = 1;
        dfs(root, cur_depth, lists);

        vector<vector<int>> ret(lists.size());
        for (int i = 0; i < lists.size(); ++i) {
            ret[i] = vector<int>{make_move_iterator(lists[i].begin()), make_move_iterator(lists[i].end())};
        }

        return ret;
    }

   private:
    void dfs(TreeNode *cur_node, int &cur_depth, vector<list<int>> &lists) {
        if (cur_depth == lists.size() + 1) {
            lists.emplace_back();
        }

        // root depth == 1
        // odd cur_depth: left->right, list emplace back
        // even cur_depth right->left, list emplace front
        if (cur_depth % 2 == 0) {
            lists[cur_depth - 1].emplace_front(cur_node->val);
        } else {
            lists[cur_depth - 1].emplace_back(cur_node->val);
        }

        if (cur_node->left != nullptr) {
            ++cur_depth;
            dfs(cur_node->left, cur_depth, lists);
            --cur_depth;
        }
        if (cur_node->right != nullptr) {
            ++cur_depth;
            dfs(cur_node->right, cur_depth, lists);
            --cur_depth;
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
