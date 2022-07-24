#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
    // process edges into adj_list
    vector<unordered_set<int>> adj_list(n);
    for (auto& edge : edges) {
      adj_list[edge[0]].emplace(edge[1]);
    }

    vector<bool> visited(n, false);
    bool all_true = true;
    dfs(source, source, destination, visited, adj_list, all_true);

    return all_true;
  }

 private:
  void dfs(int cur_node, int source, int destination, vector<bool>& visited, vector<unordered_set<int>>& adj_list, bool& all_true) {
    // stop recursion if even one non-destination end node is found
    if (!all_true) {
      return;
    }

    // end found
    if (adj_list[cur_node].empty()) {
      all_true = (cur_node == destination);
      return;
    }

    // cycle detected
    if (visited[cur_node]) {
      all_true = false;
      return;
    }

    // visit current node
    visited[cur_node] = true;

    // explore neighbours
    for (auto& nei : adj_list[cur_node]) {
      dfs(nei, source, destination, visited, adj_list, all_true);
      // backtrack
      visited[nei] = false;
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
  int n;
  vector<vector<int>> edges;
  int source;
  int destination;
  bool output;

  n = 5;
  edges = {{0, 1}, {0, 2}, {0, 3}, {0, 3}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  source = 0;
  destination = 4;
  output = solution.leadsToDestination(n, edges, source, destination);
  cout << (output ? "true\n" : "false\n");
  assert(output == true);

  cout << "Great success!" << '\n';
}
