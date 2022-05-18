#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Parse undirected graph into doubly-directed graph
        // First, initialize a vector of size n containing all empty vectors
        vector<unordered_set<int>> adj(n);
        // Doubly link each connection
        for (auto connection : connections) {
            adj[connection[0]].insert(connection[1]);
            adj[connection[1]].insert(connection[0]);
        }

        // This vector is equivalent to the time_discovered for each node. Initialize all to -1;
        vector<int> id(n, -1);
        // This vector is the low-link value for each node. Initialize all to -1;
        vector<int> low(n, -1);
        int time = 0;

        // Start dfs at node 0. This single dfs will cover all nodes due to forgiving question constraints
        vector<vector<int>> ret;
        dfs(0, -1, time, id, low, adj, ret);

        return ret;
    }

   private:
    void dfs(int cur_node, int prev_node, int& time, vector<int>& id, vector<int>& low, vector<unordered_set<int>>& adj, vector<vector<int>>& ret) {
        // when first visiting (and we only visit each node once), assign id and low to discovery time
        id[cur_node] = time;
        low[cur_node] = time;
        ++time;

        // For each outgoing edge from cur_node
        for (auto nei : adj[cur_node]) {
            // don't consider the node we just came from
            if (nei == prev_node) {
                continue;
            }

            // if neighbour not yet visited
            if (id[nei] == -1) {
                // visit
                dfs(nei, cur_node, time, id, low, adj, ret);
                // on callback, propagate the lowest low value found
                low[cur_node] = min(low[cur_node], low[nei]);
                if (id[cur_node] < low[nei]) {
                    ret.push_back({cur_node, nei});
                }
            } else {
                // if neighbour already visited, then propagage the lowest discovery time
                low[cur_node] = min(low[cur_node], id[nei]);
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

void print_adj_mat(vector<vector<int>>& connections, int n) {
    vector<vector<bool>> mat(n, vector<bool>(n, false));
    for (auto connection : connections) {
        mat[connection[0]][connection[1]] = true;
        mat[connection[1]][connection[0]] = true;
    }

    for (auto row : mat) {
        for (auto element : row) {
            cout << element << ",";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    int n;
    vector<vector<int>> connections;
    vector<vector<int>> output;

    // {}
    n = 10;
    connections = {{1, 0}, {2, 0}, {3, 0}, {4, 1}, {5, 3}, {6, 1}, {7, 2}, {8, 1}, {9, 6}, {9, 3}, {3, 2}, {4, 2}, {7, 4}, {6, 2}, {8, 3}, {4, 0}, {8, 6}, {6, 5}, {6, 3}, {7, 5}, {8, 0}, {8, 5}, {5, 4}, {2, 1}, {9, 5}, {9, 7}, {9, 4}, {4, 3}};
    // print_adj_mat(connections, n);
    output = solution.criticalConnections(n, connections);
    for (auto bridge : output) {
        print_vector(bridge);
        cout << ", ";
    }
    cout << endl;

    // {1, 0}
    n = 5;
    connections = {{1, 0}, {2, 0}, {3, 2}, {4, 2}, {4, 3}, {3, 0}, {4, 0}};
    output = solution.criticalConnections(n, connections);
    for (auto bridge : output) {
        print_vector(bridge);
        cout << ", ";
    }
    cout << endl;

    // {0, 1}, {1, 2}, {2, 3}
    n = 9;
    connections = {{0, 1}, {1, 7}, {1, 6}, {7, 6}, {1, 2}, {2, 5}, {5, 4}, {4, 2}, {2, 3}};
    output = solution.criticalConnections(n, connections);
    for (auto bridge : output) {
        print_vector(bridge);
        cout << ", ";
    }
    cout << endl;

    // {1, 3}
    n = 4;
    connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    output = solution.criticalConnections(n, connections);
    for (auto bridge : output) {
        print_vector(bridge);
        cout << ", ";
    }
    cout << endl;

    // {4, 2}, {5, 2}
    n = 6;
    connections = {{0, 3}, {0, 1}, {0, 2}, {3, 2}, {2, 1}, {4, 2}, {5, 2}};
    output = solution.criticalConnections(n, connections);
    for (auto bridge : output) {
        print_vector(bridge);
        cout << ", ";
    }
    cout << endl;
}
