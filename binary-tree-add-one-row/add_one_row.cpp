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
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      return new TreeNode(val, root, nullptr);
    }

    int cur_depth = 1;
    dfs(root, cur_depth, val, depth);

    return root;
  }

 private:
  void dfs(TreeNode *cur_node, int &cur_depth, int &val, int &depth) {
    if (cur_depth == depth - 1) {
      TreeNode *old_left = cur_node->left;
      cur_node->left = new TreeNode(val, old_left, nullptr);
      TreeNode *old_right = cur_node->right;
      cur_node->right = new TreeNode(val, nullptr, old_right);
      return;
    }

    if (cur_node->left != nullptr) {
      ++cur_depth;
      dfs(cur_node->left, cur_depth, val, depth);
      --cur_depth;
    }

    if (cur_node->right != nullptr) {
      ++cur_depth;
      dfs(cur_node->right, cur_depth, val, depth);
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
