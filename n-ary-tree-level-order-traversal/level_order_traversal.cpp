#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    if (root == nullptr) {
      return {};
    }

    unordered_map<int, int> hashmap;
    dfs_get_info(root, 0, hashmap);

    vector<vector<int>> ret(hashmap.size());
    for (int i = 0; i < ret.size(); ++i) {
      ret[i].resize(hashmap[i]);
    }

    dfs_populate(root, 0, hashmap, ret);

    return ret;
  }

 private:
  void dfs_get_info(Node* cur_node, int cur_depth, unordered_map<int, int>& hashmap) {
    ++hashmap[cur_depth];
    for (Node*& child : cur_node->children) {
      dfs_get_info(child, cur_depth + 1, hashmap);
    }
  }

  void dfs_populate(Node* cur_node, int cur_depth, unordered_map<int, int>& hashmap, vector<vector<int>>& ret) {
    --hashmap[cur_depth];
    ret[cur_depth][hashmap[cur_depth]] = cur_node->val;

    for (int i = cur_node->children.size() - 1; i >= 0; --i) {
      dfs_populate(cur_node->children[i], cur_depth + 1, hashmap, ret);
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
