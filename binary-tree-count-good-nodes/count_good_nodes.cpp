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
  int goodNodes(TreeNode *root) {
    int ret = 0;
    dfs(root, -10001, ret);
    return ret;
  }

 private:
  void dfs(TreeNode *cur_node, int prev_biggest, int &ret) {
    int cur_biggest = prev_biggest;
    if (cur_node->val >= prev_biggest) {
      ++ret;
      cur_biggest = cur_node->val;
    }

    if (cur_node->left != nullptr) {
      dfs(cur_node->left, cur_biggest, ret);
    }

    if (cur_node->right != nullptr) {
      dfs(cur_node->right, cur_biggest, ret);
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
