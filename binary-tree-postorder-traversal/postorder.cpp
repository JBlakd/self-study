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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }

   private:
    void dfs(TreeNode *cur_node, vector<int> &ret) {
        if (cur_node == nullptr) {
            return;
        }

        dfs(cur_node->left, ret);
        dfs(cur_node->right, ret);
        ret.push_back(cur_node->val);
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
