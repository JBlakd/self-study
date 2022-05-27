#include <algorithm>
#include <iostream>
#include <limits>
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

        // Have to modify dijkstra to allow revisiting of nodes if:
        // - Just found a path with shorter distance
        // - Just found a path with fewer stops

        // TODO: for complicates shit like this, it's better to track statistics at each node.
        // i.e. at the current node, track the cost it took to get here using the current path (though we still prioritise shortest path found)
        // also track the stops it took to get here at the current node
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
