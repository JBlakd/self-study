#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // vector<vector<int>> prev(rows, vector<int>(cols, -1));
        vector<vector<int>> dist(rows, vector<int>(cols, 1000000));

        // Min priority queue of vertices, prioritising minimum effort
        //             <effort, x, y>
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Initialize for origin (top left corner)
        dist[0][0] = 0;
        pq.push(make_tuple(0, 0, 0));

        while (!pq.empty()) {
            tuple<int, int, int> cur_node = pq.top();
            int cur_effort = get<0>(cur_node);
            int cur_x = get<1>(cur_node);
            int cur_y = get<2>(cur_node);
            pq.pop();

            // return if found
            // if (cur_x == cols - 1 && cur_y == rows - 1) {
            //     return dist[cur_x][cur_y];
            // }

            // Calculate neighbours
            vector<tuple<int, int, int>> neighbours;
            for (auto direction : directions) {
                pair<int, int> potential_neighbour = make_pair(cur_x + direction.first, cur_y + direction.second);
                // reject if out of bounds
                if (potential_neighbour.first < 0 || potential_neighbour.first >= rows || potential_neighbour.second < 0 || potential_neighbour.second >= cols) {
                    continue;
                }

                int n_height = heights[potential_neighbour.first][potential_neighbour.second];
                // calculate total effort to reach neighbour through cur_node
                int potential_effort = max(cur_effort, abs(n_height - heights[cur_x][cur_y]));

                // If this path to reach this neighbour is better than current best known path
                if (potential_effort < dist[potential_neighbour.first][potential_neighbour.second]) {
                    // Update best known path
                    dist[potential_neighbour.first][potential_neighbour.second] = potential_effort;
                    // update prev (not needed in this problem)
                    pq.push(make_tuple(potential_effort, potential_neighbour.first, potential_neighbour.second));
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> input;

    input = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << solution.minimumEffortPath(input) << endl;

    input = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    cout << solution.minimumEffortPath(input) << endl;

    input = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    cout << solution.minimumEffortPath(input) << endl;
}
