#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Parse undirected graph into doubly-directed graph
        // First, initialize a vector of size n containing all empty vectors
        vector<vector<int>> adj(n);
        // Doubly link each connection
        for (auto connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        // Start dfs at node 0. This single dfs will cover all nodes due to forgiving question constraints
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
}
