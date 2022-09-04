#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
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
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    unordered_map<int, vector<int>> hashmap;
    int lowest = 0;
    dfs(root, 0, hashmap, lowest);
    vector<vector<int>> ret(hashmap.size());
    for (auto &[key, val] : hashmap) {
      sort(val.begin(), val.end());
      ret[key - lowest] = val;
    }
    return ret;
  }

 private:
  void dfs(TreeNode *cur_node, int cur_offset, unordered_map<int, vector<int>> &hashmap, int &lowest) {
    lowest = min(lowest, cur_offset);
    if (hashmap.find(cur_offset) == hashmap.end()) {
      hashmap[cur_offset] = vector<int>(1, cur_node->val);
    } else {
      hashmap[cur_offset].push_back(cur_node->val);
    }

    if (cur_node->left != nullptr) {
      dfs(cur_node->left, cur_offset - 1, hashmap, lowest);
    }
    if (cur_node->right != nullptr) {
      dfs(cur_node->right, cur_offset + 1, hashmap, lowest);
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
  vector<vector<int>> output;

  node_vals = {3, 9, 20, -1, -1, 15, 7};
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
  output = solution.verticalTraversal(input[0]);
  for (auto node : input) {
    delete node;
  }
  input.clear();
  node_vals.clear();

  cout << "Great success!" << '\n';
}
