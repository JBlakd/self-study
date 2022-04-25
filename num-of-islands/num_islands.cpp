#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        rows = grid.size();
        cols = grid[0].size();

        vector<vector<bool>> marked(rows, vector<bool>(cols, false));

        int num_islands = 0;

        // BFS
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (marked[row][col]) {
                    continue;
                }

                char current_tile_type;
                if (grid[row][col] == '1') {
                    ++num_islands;
                    current_tile_type = '1';
                } else {
                    current_tile_type = '0';
                }

                marked[row][col] = true;
                queue<pair<int, int>> q;
                q.push({row, col});

                while (!q.empty()) {
                    pair<int, int> cur_pos = q.front();
                    q.pop();
                    for (auto neighbor : adj(cur_pos.first, cur_pos.second)) {
                        if (!marked[neighbor.first][neighbor.second] && grid[neighbor.first][neighbor.second] == current_tile_type) {
                            marked[neighbor.first][neighbor.second] = true;
                            q.push({neighbor.first, neighbor.second});
                        }
                    }
                }
            }
        }

        return num_islands;
    }

   private:
    int rows;
    int cols;

    vector<pair<int, int>> adj(int row, int col) {
        // Extreme case single tile grid
        if (cols == 1 && rows == 1) {
            return {};
        }

        // Extreme case single row grid
        if (rows == 1) {
            // Left corner
            if (col == 0) {
                return {{row, col + 1}};
            }

            // Right corner
            if (col == cols - 1) {
                return {{row, col - 1}};
            }

            // Non corner
            return {{row, col - 1}, {row, col + 1}};
        }

        // Extreme case single col grid
        if (cols == 1) {
            // Top corner
            if (row == 0) {
                return {{row + 1, col}};
            }

            // Bottom corner
            if (row == rows - 1) {
                return {{row - 1, col}};
            }

            // Non corner
            return {{row - 1, col}, {row + 1, col}};
        }

        // Top row left corner
        if (row == 0 && col == 0) {
            return {{row, col + 1}, {row + 1, col}};
        }

        // Top row right corner
        if (row == 0 && col == cols - 1) {
            return {{row, col - 1}, {row + 1, col}};
        }

        // Top row non corner
        if (row == 0) {
            return {{row, col + 1}, {row, col - 1}, {row + 1, col}};
        }

        // Bottom row left corner
        if (row == rows - 1 && col == 0) {
            return {{row, col + 1}, {row - 1, col}};
        }

        // Bottom row right corner
        if (row == rows - 1 && col == cols - 1) {
            return {{row, col - 1}, {row - 1, col}};
        }

        // Bottom row non corner
        if (row == rows - 1) {
            return {{row, col - 1}, {row, col + 1}, {row - 1, col}};
        }

        // Left col non corner
        if (col == 0) {
            return {{row, col + 1}, {row - 1, col}, {row + 1, col}};
        }

        // Right col non corner
        if (col == cols - 1) {
            return {{row, col - 1}, {row - 1, col}, {row + 1, col}};
        }

        // Non edge
        return {{row - 1, col}, {row, col - 1}, {row, col + 1}, {row + 1, col}};
    }
};

int main() {
    Solution solution;
    vector<vector<char>> input;
    input = {{'1'}, {'0'}, {'1'}, {'0'}, {'1'}, {'1'}};
    cout << "Meant to be 3: " << solution.numIslands(input) << endl;

    input = {{'1'}};
    cout << solution.numIslands(input) << endl;

    input = {{'1', '1', '0', '1', '0'}};  // 2
    cout << solution.numIslands(input) << endl;

    input = {{'1'}, {'1'}, {'0'}, {'1'}, {'0'}};  // 2
    cout << solution.numIslands(input) << endl;

    input = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};  // 1
    cout << solution.numIslands(input) << endl;

    input = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};  // 3
    cout << solution.numIslands(input) << endl;
}
