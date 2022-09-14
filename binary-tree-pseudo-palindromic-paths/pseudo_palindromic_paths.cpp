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
  int pseudoPalindromicPaths(TreeNode *root) {
    int ret = 0;
    vector<int> arr(10, 0);
    dfs(root, arr, ret);
    return ret;
  }

 private:
  void dfs(TreeNode *cur_node, vector<int> &arr, int &ret) {
    ++arr[cur_node->val];

    if (cur_node->left == nullptr && cur_node->right == nullptr) {
      if (is_palindromic(arr)) {
        ++ret;
      }
    }

    if (cur_node->left != nullptr) {
      dfs(cur_node->left, arr, ret);
    }
    if (cur_node->right != nullptr) {
      dfs(cur_node->right, arr, ret);
    }

    --arr[cur_node->val];
  }

  bool is_palindromic(vector<int> &arr) {
    int total = 0;
    int num_odds = 0;
    for (int i = 1; i <= 9; ++i) {
      if (arr[i] % 2 != 0) {
        ++num_odds;
      }

      if (num_odds >= 2) {
        return false;
      }

      total += arr[i];
    }

    if (total % 2 != 0) {
      return num_odds == 1;
    } else {
      return num_odds == 0;
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
