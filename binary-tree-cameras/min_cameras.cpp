#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
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
    int minCameraCover(TreeNode *root) {
        // if (root->left == nullptr && root->right == nullptr) {
        //     return 1;
        // }
        unordered_set<TreeNode *> monitored;
        unordered_set<TreeNode *> cameras;
        dfs(root, nullptr, cameras, monitored);
        // Gotta consider returning from the root as well!
        if (monitored.find(root) == monitored.end()) {
            cameras.emplace(root);
        }
        return cameras.size();
    }

   private:
    void dfs(TreeNode *cur_node, TreeNode *parent, unordered_set<TreeNode *> &cameras, unordered_set<TreeNode *> &monitored) {
        if (cur_node->left != nullptr) {
            dfs(cur_node->left, cur_node, cameras, monitored);
            // Put a camera at cur_node whenever returning from a non-monitored node
            // Also make sure there isn't already a camera at the cur_node
            if (monitored.find(cur_node->left) == monitored.end()) {
                // put camera
                cameras.emplace(cur_node);
                monitored.emplace(cur_node);
                monitored.emplace(cur_node->left);
                if (parent != nullptr) {
                    monitored.emplace(parent);
                }
                if (cur_node->right != nullptr) {
                    monitored.emplace(cur_node->right);
                }
            }
        }

        if (cur_node->right != nullptr) {
            dfs(cur_node->right, cur_node, cameras, monitored);
            // Put a camera at cur_node whenever returning from a non-monitored node
            // Also make sure there isn't already a camera at the cur_node
            if (monitored.find(cur_node->right) == monitored.end()) {
                // put camera
                cameras.emplace(cur_node);
                monitored.emplace(cur_node);
                monitored.emplace(cur_node->right);
                if (parent != nullptr) {
                    monitored.emplace(parent);
                }
                if (cur_node->left != nullptr) {
                    monitored.emplace(cur_node->left);
                }
            }
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
