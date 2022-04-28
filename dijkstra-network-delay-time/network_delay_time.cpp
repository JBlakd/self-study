#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Maintain a vector of edges vectors for each node
        // The index represents the source node
        // The vector at the index contains all the outgoing edges
        // The zero index is wasted because there are no zero-labelled nodes
        // Indices 1 to n will be used
        // Each edge is formatted as <dest_node, weight>
        vector<vector<pair<int, int>>> adj_list(n + 1);
        for (auto edge : times) {
            adj_list[edge[0]].push_back(make_pair(edge[1], edge[2]));
        }

        // Initialise all distance to one more than max allowed distance (simulate infinity)
        vector<int> dist(n + 1, 101);

        // priority queue of vertices, prioritised by minimum distance to get to it
        priority_queue<pair<int, int>> pq;

        // Initialise origin
        dist[k] = 0;
        pq.push(make_pair(0, k));

        while (!pq.empty()) {
            int cur_node = pq.top().second;
            pq.pop();

            // Loop through neighbours
            for (auto edge : adj_list[cur_node]) {
                int neighbour = edge.first;
                int potential_best_dist = dist[cur_node] + edge.second;
                if (potential_best_dist < dist[neighbour]) {
                    dist[neighbour] = potential_best_dist;
                    pq.push(make_pair(edge.second, neighbour));
                }
            }
        }

        // return max dist (dist of the furthest node)
        int max_dist = -1;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 101) {
                return -1;
            }

            if (dist[i] > max_dist) {
                max_dist = dist[i];
            }
        }

        return max_dist;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> times;
    int n, k;

    times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    n = 4;
    k = 2;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1, 2, 1}};
    n = 2;
    k = 1;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1, 2, 1}};
    n = 2;
    k = 2;
    cout << solution.networkDelayTime(times, n, k) << endl;
}
