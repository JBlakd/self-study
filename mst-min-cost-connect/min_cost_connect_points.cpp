#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> is_visited(points.size());
        int num_visited = 0;
        int min_weight = 0;

        // min priority queue of weighted edges: <weight, v, w>. Low weight edges are prioritised
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        is_visited[0] = true;
        ++num_visited;
        for (int i = 1; i < points.size(); ++i) {
            // This check is not necessary because this is still the initial condition
            // DO NOT FORGET LATER ON
            // if (!is_visited[i]) {
            int weight = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
            pq.push(make_tuple(weight, 0, i));
            // }
        }

        // Continuously visit
        while (num_visited < points.size()) {
            // Set current edge to the min-weighted edge discovered so far
            while (is_visited[get<2>(pq.top())]) {
                pq.pop();
            }
            tuple<int, int, int> cur_edge = pq.top();
            pq.pop();
            int& cur_point = get<2>(cur_edge);

            // Visit the node that the current edge is connected to
            is_visited[cur_point] = true;
            ++num_visited;
            // Add this min-weighted edge's weight to the cumulative value
            min_weight += get<0>(cur_edge);

            // Loop through all neighbouring unvisited nodes (all other nodes)
            for (int i = 0; i < points.size(); ++i) {
                if (is_visited[i]) {
                    continue;
                }

                //           this point                 other point
                int weight = abs(points[cur_point][0] - points[i][0]) +
                             abs(points[cur_point][1] - points[i][1]);

                pq.push(make_tuple(weight, cur_point, i));
            }
        }

        return min_weight;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> input;

    input = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << "Expected output: 20. Got output: " << solution.minCostConnectPoints(input) << endl;

    input = {{3, 12}, {-2, 5}, {-4, 1}};
    cout << "Expected output: 18. Got output: " << solution.minCostConnectPoints(input) << endl;
}
