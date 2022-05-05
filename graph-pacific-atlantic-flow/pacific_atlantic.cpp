#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) {
            return {};
        }

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> p_visited(rows, vector<bool>(cols, false));
        vector<vector<bool>> a_visited(rows, vector<bool>(cols, false));

        const vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // Before conducting dfs to both oceans, initialize each coastal tile to have visited their respective ocean
        // for (int i = 0; i < cols; i++) {
        //     p_visited[0][i] = true;
        // }
        // for (int i = 0; i < rows; i++) {
        //     p_visited[i][0] = true;
        // }
        // for (int i = 0; i < cols; i++) {
        //     a_visited[rows - 1][i] = true;
        // }
        // for (int i = 0; i < rows; i++) {
        //     a_visited[i][cols - 1] = true;
        // }

        // Conduct one dfs for each ocean for each coastal tile. Any tile reachable from a coastal tile can flow into the ocean
        for (int row = 0; row < rows; row++) {
            dfs(heights, row, 0, p_visited, directions);
            dfs(heights, row, cols - 1, a_visited, directions);
        }
        for (int col = 0; col < cols; col++) {
            dfs(heights, 0, col, p_visited, directions);
            dfs(heights, rows - 1, col, a_visited, directions);
        }

        vector<vector<int>> ret;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (p_visited[row][col] && a_visited[row][col]) {
                    ret.push_back({row, col});
                }
            }
        }

        return ret;
    }

   private:
    int rows;
    int cols;

    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<bool>>& visited, const vector<pair<int, int>>& directions) {
        if (visited[row][col]) {
            return;
        }
        visited[row][col] = true;

        for (auto direction : directions) {
            if (is_valid_direction(row, col, direction, heights)) {
                dfs(heights, row + direction.first, col + direction.second, visited, directions);
            }
        }
    }

    bool is_valid_direction(int row, int col, pair<int, int>& direction, vector<vector<int>>& heights) {
        // First check if that direction is out of bounds
        if (!(row + direction.first < 0 || row + direction.first >= rows || col + direction.second < 0 || col + direction.second >= cols)) {
            // Then check if that direction is equal or HIGHER elevation
            // Higher because we are searching from coastal tiles, i.e. searching from low to higher elevation
            if (heights[row + direction.first][col + direction.second] >= heights[row][col]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> input;
    vector<vector<int>> output;

    input = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    output = solution.pacificAtlantic(input);
    for (auto coordinates : output) {
        cout << "[" << coordinates[0] << "," << coordinates[1] << "],";
    }
    cout << endl;
}
