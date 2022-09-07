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
  string tree2str(TreeNode *root) {
    string ret = "";
    dfs(root, ret);
    return ret;
  }

 private:
  void dfs(TreeNode *cur_node, string &ret) {
    ret.append(to_string(cur_node->val));

    // if no children exists
    if (cur_node->left == nullptr && cur_node->right == nullptr) {
      return;
    }

    // mandatory left child parenthesis start
    ret.append("(");
    if (cur_node->left != nullptr) {
      dfs(cur_node->left, ret);
    }
    // mandatory left child parenthesis end
    ret.append(")");

    // explore right child, this time the parentheses are conditional on the existence of the right child
    if (cur_node->right != nullptr) {
      ret.append("(");
      dfs(cur_node->right, ret);
      ret.append(")");
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
