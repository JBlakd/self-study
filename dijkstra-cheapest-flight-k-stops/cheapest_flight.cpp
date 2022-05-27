#include <algorithm>
#include <iostream>
#include <limits>
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

        int ret = numeric_limits<int>::max();
        dfs(src, dst, k + 1, 0, ret, adj);
        if (ret == numeric_limits<int>::max()) {
            return -1;
        }
        return ret;
    }

   private:
    void dfs(int cur_node, int dst, int num_jumps_allowed, int cur_price, int& ret, vector<vector<pair<int, int>>>& adj) {
        // Base case: node found
        if (cur_node == dst) {
            ret = min(ret, cur_price);
            return;
        }

        if (num_jumps_allowed == 0) {
            return;
        }

        for (auto& [nei, nei_price] : adj[cur_node]) {
            // don't explore a neighbour if it costs more than answer found so far
            if (cur_price + nei_price > ret) {
                continue;
            }
            dfs(nei, dst, num_jumps_allowed - 1, cur_price + nei_price, ret, adj);
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
    vector<vector<int>> flights;
    int src;
    int dst;
    int k;

    // 30054
    n = 10;
    flights = {{0, 1, 20}, {1, 2, 20}, {2, 3, 30}, {3, 4, 30}, {4, 5, 30}, {5, 6, 30}, {6, 7, 30}, {7, 8, 30}, {8, 9, 30}, {0, 2, 9999}, {2, 4, 9998}, {4, 7, 9997}};
    src = 0;
    dst = 9;
    k = 4;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;

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
