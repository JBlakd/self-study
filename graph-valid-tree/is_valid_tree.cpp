#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // just detect cycles? And also detect disconnected components.

        vector<unordered_set<int>> adj_list(n);
        for (auto& edge : edges) {
            adj_list[edge[0]].emplace(edge[1]);
            adj_list[edge[1]].emplace(edge[0]);
        }

        int visited_count = 0;
        vector<bool> visited(n, false);
        bool abort = false;
        if (dfs(0, visited, adj_list, abort, visited_count)) {
            // Cycle detected, not valid tree
            return false;
        }

        // valid tree detected, but are all components detected?
        if (visited_count < n) {
            // there are 2 or more components in the set of nodes, therefore not valid tree
            return false;
        } else {
            // the entire set of nodes is a valid tree
            return true;
        }
    }

   private:
    // returns true if cycle detected
    bool dfs(int cur_node, vector<bool>& visited, vector<unordered_set<int>>& adj_list, bool& abort, int& visited_count) {
        if (abort) {
            return true;
        }

        visited[cur_node] = true;
        ++visited_count;

        // visit neighbour, but before doing so, turn the undirected edge into a forward-directed one (prevents backtracking except for return)
        for (auto& nei : adj_list[cur_node]) {
            // if we are about to visit an already-visited neighbour, return true
            if (visited[nei] || abort) {
                abort = true;
                return true;
            }

            adj_list[nei].erase(cur_node);
            dfs(nei, visited, adj_list, abort, visited_count);
        }

        return abort;
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

    // 0
    n = 5;
    edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << solution.validTree(5, edges) << '\n';
}
