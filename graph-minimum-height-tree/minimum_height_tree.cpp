#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        // Parse edges into adjacency list
        vector<vector<int>> adj_list(n);
        for (auto& edge : edges) {
            adj_list[edge[0]].emplace_back(edge[1]);
            adj_list[edge[1]].emplace_back(edge[0]);
        }

        // Find the most outlying node within this tree to constitute one endpoint of our longest path.
        // This can be done via DFS starting from any node
        int endpoint_1 = -1;
        int max_dist = 0;
        vector<bool> visited(n, false);
        dfs(0, 0, max_dist, endpoint_1, adj_list, visited);

        // Find longest path via BFS
        int endpoint_2 = -1;
        max_dist = 0;
        visited.assign(n, false);
        vector<int> from(n, -1);
        dfs_path(endpoint_1, 0, max_dist, endpoint_2, from, adj_list, visited);

        // Construct the path by retracing from
        int cur_node = endpoint_2;
        vector<int> ret;
        ret.push_back(endpoint_2);
        while (from[cur_node] != -1) {
            ret.push_back(from[cur_node]);
            cur_node = from[cur_node];
        }
        // ret.push_back(endpoint_1);

        // ret now contains the longest path
        if (ret.size() % 2 == 0) {
            return vector<int>(ret.begin() + (ret.size() / 2) - 1, ret.begin() + (ret.size() / 2) + 1);
        } else {
            return vector<int>(ret.begin() + (ret.size() / 2), ret.begin() + (ret.size() / 2) + 1);
        }
    }

   private:
    void dfs(int cur_node, int cur_dist, int& max_dist, int& furthest_node, vector<vector<int>>& adj_list, vector<bool>& visited) {
        if (cur_dist > max_dist) {
            max_dist = cur_dist;
            furthest_node = cur_node;
        }
        visited[cur_node] = true;
        for (auto nei : adj_list[cur_node]) {
            if (!visited[nei]) {
                dfs(nei, cur_dist + 1, max_dist, furthest_node, adj_list, visited);
            }
        }
    }

    void dfs_path(int cur_node, int cur_dist, int& max_dist, int& furthest_node, vector<int>& from, vector<vector<int>>& adj_list, vector<bool>& visited) {
        if (cur_dist > max_dist) {
            max_dist = cur_dist;
            furthest_node = cur_node;
        }
        visited[cur_node] = true;
        for (auto nei : adj_list[cur_node]) {
            if (!visited[nei]) {
                from[nei] = cur_node;
                dfs_path(nei, cur_dist + 1, max_dist, furthest_node, from, adj_list, visited);
            }
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
    vector<int> output;

    // 0, 1
    n = 2;
    edges = {{1, 0}};
    output = solution.findMinHeightTrees(n, edges);
    print_vector(output);
    cout << '\n';

    // 3, 4
    n = 6;
    edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    output = solution.findMinHeightTrees(n, edges);
    print_vector(output);
    cout << '\n';

    // 1
    n = 4;
    edges = {{1, 0}, {1, 2}, {1, 3}};
    output = solution.findMinHeightTrees(n, edges);
    print_vector(output);
    cout << '\n';
}
