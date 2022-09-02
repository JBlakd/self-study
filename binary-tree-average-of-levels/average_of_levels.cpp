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
  vector<double> averageOfLevels(TreeNode *root) {
    int depth = 0;
    int max_depth = 0;
    dfs_find_max_depth(root, depth, max_depth);

    vector<int> num_nodes_by_level(max_depth, 0);
    vector<double> ret(max_depth, 0);
    dfs(root, 0, num_nodes_by_level, ret);

    return ret;
  }

 private:
  void dfs_find_max_depth(TreeNode *cur_node, int &depth, int &max_depth) {
    ++depth;
    max_depth = max(max_depth, depth);
    if (cur_node->left != nullptr) {
      dfs_find_max_depth(cur_node->left, depth, max_depth);
    }
    if (cur_node->right != nullptr) {
      dfs_find_max_depth(cur_node->right, depth, max_depth);
    }
    --depth;
  }

  void dfs(TreeNode *cur_node, int cur_level, vector<int> &num_nodes_by_level, vector<double> &ret) {
    ret[cur_level] = num_nodes_by_level[cur_level] * ret[cur_level] + cur_node->val;
    ++num_nodes_by_level[cur_level];
    ret[cur_level] /= num_nodes_by_level[cur_level];

    if (cur_node->left != nullptr) {
      dfs(cur_node->left, cur_level + 1, num_nodes_by_level, ret);
    }
    if (cur_node->right != nullptr) {
      dfs(cur_node->right, cur_level + 1, num_nodes_by_level, ret);
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
