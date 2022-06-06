#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // BFS, but with multiple initial "rotten" nodes
        //         <row, col, time>
        queue<tuple<int, int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int time_of_last_explored_node = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j, 0);
                    grid[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [cur_row, cur_col, cur_time] = q.front();
            q.pop();

            for (auto& [dx, dy] : dirs) {
                int nei_row = cur_row + dx;
                int nei_col = cur_col + dy;

                if (nei_row < 0 || nei_col < 0 || nei_row >= rows || nei_col >= cols || grid[nei_row][nei_col] != 1) {
                    continue;
                }

                grid[nei_row][nei_col] = cur_time - 1;
                time_of_last_explored_node = grid[nei_row][nei_col];
                q.emplace(nei_row, nei_col, grid[nei_row][nei_col]);
            }
        }

        // Check over all oranges to make sure all are rotten;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    // If some oranges are still fresj, return -1
                    return -1;
                }
            }
        }

        return -1 * time_of_last_explored_node;
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
    vector<vector<int>> grid;

    // -1
    grid = {{1, 0, 2}};
    cout << solution.orangesRotting(grid) << '\n';

    // 0
    grid = {{0}};
    cout << solution.orangesRotting(grid) << '\n';

    // 4
    grid = {{2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}};
    cout << solution.orangesRotting(grid) << '\n';

    // -1
    grid = {{2, 1, 1},
            {0, 1, 1},
            {1, 0, 1}};
    cout << solution.orangesRotting(grid) << '\n';

    // 0
    grid = {{0, 2}};
    cout << solution.orangesRotting(grid) << '\n';
}
