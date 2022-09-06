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
  TreeNode *pruneTree(TreeNode *root) {
    dfs_prune(root);

    if (root->left == nullptr && root->right == nullptr && root->val == 0) {
      return nullptr;
    }

    return root;
  }

 private:
  bool dfs_is_all_zeros(TreeNode *cur_node) {
    if (cur_node == nullptr) {
      return true;
    }

    if (dfs_is_all_zeros(cur_node->left) && dfs_is_all_zeros(cur_node->right)) {
      return cur_node->val == 0;
    } else {
      return false;
    }
  }

  void dfs_prune(TreeNode *cur_node) {
    if (dfs_is_all_zeros(cur_node->left)) {
      cur_node->left = nullptr;
    }

    if (dfs_is_all_zeros(cur_node->right)) {
      cur_node->right = nullptr;
    }

    if (cur_node->left != nullptr) {
      dfs_prune(cur_node->left);
    }
    if (cur_node->right != nullptr) {
      dfs_prune(cur_node->right);
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
  TreeNode *output;

  node_vals = {1, -1, 0, -1, -1, 0, 1};
  // Node initialisation
  for (int val : node_vals) {
    if (val == -1) {
      input.push_back(nullptr);
      continue;
    }
    TreeNode *cur_node = new TreeNode(val);
    input.push_back(cur_node);
  }
  // Node connection
  for (int i = 0; i < input.size(); ++i) {
    int left_index = (i + 1) * 2 - 1;
    int right_index = (i + 1) * 2;

    if (input[i] == nullptr) {
      continue;
    }

    if (left_index < input.size()) {
      input[i]->left = input[left_index];
    }
    if (right_index < input.size()) {
      input[i]->right = input[right_index];
    }
  }
  output = solution.pruneTree(input[0]);
  for (auto node : input) {
    delete node;
  }
  input.clear();
  node_vals.clear();

  cout << "Great success!" << '\n';
}
