#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (n == 1) {
            return -1;
        }

        // Parse flights into weighted adjacency list
        // Index denotes from
        // Each edge is represented by pair<to, weight>
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // Initialize distance vector
        // Index denotes dst, value denotes shortest found distance so far
        vector<int> dist(n, 10001);

        queue<int> todo;
        dist[src] = 0;
        todo.push(src);

        // TODO: check k condition
        while (k >= 0) {
            int cur_depth_nodes = todo.size();
            for (int i = 0; i < cur_depth_nodes; ++i) {
                int cur_node = todo.front();
                todo.pop();
                for (auto& [nei, weight] : adj[cur_node]) {
                    if (dist[cur_node] + weight < dist[nei]) {
                        dist[nei] = dist[cur_node] + weight;
                        todo.push(nei);
                    }
                }
            }
            // All node of the same depth explored. Can decrement k;
            k--;
        }

        if (dist[dst] == 10001) {
            return -1;
        }
        return dist[dst];
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
    vector<vector<int>> flights;
    int src;
    int dst;
    int k;

    // 6
    n = 4;
    flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
    src = 0;
    dst = 3;
    k = 1;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;

    // 700
    n = 4;
    flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    src = 0;
    dst = 3;
    k = 1;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;

    // 200
    n = 3;
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    src = 0;
    dst = 2;
    k = 1;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;

    // 500
    n = 3;
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    src = 0;
    dst = 2;
    k = 0;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;

    // -1
    n = 3;
    flights = {{0, 1, 100}, {1, 2, 100}};
    src = 0;
    dst = 2;
    k = 0;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;
}
