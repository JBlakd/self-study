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
        dfs(0, time, id, low, adj);

        // Iterate through connections. Connections with non-equal endpoint values in the low array are bridge connections
        vector<vector<int>> ret;
        for (auto connection : connections) {
            if (low[connection[0]] != low[connection[1]]) {
                ret.push_back(connection);
            }
        }
        return ret;
    }

   private:
    int dfs(int cur_node, int& time, vector<int>& id, vector<int>& low, vector<unordered_set<int>>& adj) {
        id[cur_node] = time;
        low[cur_node] = time;
        ++time;
        int cur_low = id[cur_node];

        for (auto nei : adj[cur_node]) {
            // check if neighbour is visited by seeing if it has a non -1 id
            if (id[nei] == -1) {
                // not visited
                // Before visiting, remove the in-connection from the neighbour
                // in other words, turn this bidirectional connection into a unidirectional connection
                adj[nei].erase(cur_node);
                int potential_lowest = dfs(nei, time, id, low, adj);
                low[cur_node] = min(low[cur_node], potential_lowest);
            } else {
                // already visited, so update current low and return that node's id
                // if (id[nei] <= low[cur_node]) {
                //     low[cur_node] = id[nei];
                // }
                low[cur_node] = min(low[cur_node], id[nei]);
                // cout << "test\n";
                // return id[nei];
            }
        }

        // Upon callback, determine if there's a need to update
        // Update if a cycle has been encountered. If this is the case, then cur_low will be smaller or equal to the current low
        // if (cur_low <= low[cur_node]) {
        //     low[cur_node] = cur_low;
        // }

        return low[cur_node];
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
    vector<vector<int>> connections;
    vector<vector<int>> output;

    // {}
    n = 10;
    connections = {{1, 0}, {2, 0}, {3, 0}, {4, 1}, {5, 3}, {6, 1}, {7, 2}, {8, 1}, {9, 6}, {9, 3}, {3, 2}, {4, 2}, {7, 4}, {6, 2}, {8, 3}, {4, 0}, {8, 6}, {6, 5}, {6, 3}, {7, 5}, {8, 0}, {8, 5}, {5, 4}, {2, 1}, {9, 5}, {9, 7}, {9, 4}, {4, 3}};
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
