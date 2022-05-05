#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Will be mutating grid input
        // 0 means visited
        rows = grid.size();
        cols = grid[0].size();
        directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int max_count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != 0) {
                    int count = 0;
                    dfs(i, j, grid, count);
                    if (count > max_count) {
                        max_count = count;
                    }
                }
            }
        }

        return max_count;
    }

   private:
    int rows;
    int cols;
    vector<pair<int, int>> directions;

    void dfs(int row, int col, vector<vector<int>>& grid, int& count) {
        ++count;
        grid[row][col] = 0;
        for (auto& dir : directions) {
            pair<int, int> neighbour = make_pair(row + dir.first, col + dir.second);
            // check out of bounds
            if (neighbour.first < 0 || neighbour.second < 0 || neighbour.first >= rows || neighbour.second >= cols) {
                continue;
            }
            if (grid[neighbour.first][neighbour.second] != 0) {
                dfs(neighbour.first, neighbour.second, grid, count);
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid;

    grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << solution.maxAreaOfIsland(grid) << endl;
}
