#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // find da dude
        int start_row = -1;
        int start_col = -1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '*') {
                    start_row = i;
                    start_col = j;
                    break;
                }
            }
            if (start_row != -1 && start_col != -1) {
                break;
            }
        }

        // -2 denotes wall, -1 denotes unvisited, non-negative numbers denote visited + distance
        vector<vector<int>> distance_grid(rows, vector<int>(cols, -2));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != 'X') {
                    distance_grid[i][j] = -1;
                }
            }
        }

        // BFS
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        // visit initial location
        distance_grid[start_row][start_col] = 0;
        q.emplace(start_row, start_col);

        while (!q.empty()) {
            auto [cur_row, cur_col] = q.front();
            q.pop();

            for (auto& [dy, dx] : dirs) {
                int nei_row = cur_row + dy;
                int nei_col = cur_col + dx;

                // Rejected out of bounds, and not-unvisited neighbours
                if (nei_row < 0 || nei_col < 0 || nei_row >= rows || nei_col >= cols || distance_grid[nei_row][nei_col] != -1) {
                    continue;
                }

                if (grid[nei_row][nei_col] == '#') {
                    // food found
                    return distance_grid[cur_row][cur_col] + 1;
                } else {
                    distance_grid[nei_row][nei_col] = distance_grid[cur_row][cur_col] + 1;
                    q.emplace(nei_row, nei_col);
                }
            }
        }

        // food not found
        return -1;
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
    vector<vector<char>> grid;
    int output;

    grid = {{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}, {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'}, {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'}, {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'}, {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};
    output = solution.getFood(grid);
    cout << output << '\n';
    assert((output == 6));

    grid = {{'X', 'X', 'X', 'X', 'X'}, {'X', '*', 'X', 'O', 'X'}, {'X', 'O', 'X', '#', 'X'}, {'X', 'X', 'X', 'X', 'X'}};
    output = solution.getFood(grid);
    cout << output << '\n';
    assert((output == -1));

    grid = {{'X', 'X', 'X', 'X', 'X', 'X'}, {'X', '*', 'O', 'O', 'O', 'X'}, {'X', 'O', 'O', '#', 'O', 'X'}, {'X', 'X', 'X', 'X', 'X', 'X'}};
    output = solution.getFood(grid);
    cout << output << '\n';
    assert((output == 3));

    cout << "Great success!" << '\n';
}
