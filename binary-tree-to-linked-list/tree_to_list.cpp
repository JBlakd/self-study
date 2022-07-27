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
  void flatten(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    TreeNode *list_head = nullptr;
    TreeNode *virtual_head = new TreeNode();
    dfs(virtual_head, root);
    // cout << root->val;
  }

 private:
  void dfs(TreeNode *&list_head, TreeNode *cur_node) {
    TreeNode *left_copy = cur_node->left;
    TreeNode *right_copy = cur_node->right;
    list_head->right = cur_node;
    list_head->left = nullptr;
    list_head = cur_node;
    if (left_copy != nullptr) {
      dfs(list_head, left_copy);
    }
    if (right_copy != nullptr) {
      dfs(list_head, right_copy);
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
