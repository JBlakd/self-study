#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();

        vector<vector<int>> memo(rows, vector<int>(cols, 0));

        int ret = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ret = max(ret, dfs(i, j, matrix, memo));
            }
        }

        return ret;
    }

   private:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        // Already calculated. Return memoized value
        if (memo[row][col] != 0) {
            return memo[row][col];
        }

        // Initialize minimum path length
        memo[row][col] = 1;

        for (auto dir : dirs) {
            int nei_row = row + dir[0];
            int nei_col = col + dir[1];

            // Reject out of bounds, and <= neighbours
            if (nei_row < 0 || nei_col < 0 || nei_row >= rows || nei_col >= cols || matrix[nei_row][nei_col] <= matrix[row][col]) {
                continue;
            }

            // Current answer must be 1 more than the reachable neighbour's answer if the already-memoized value is not optimal
            memo[row][col] = max(memo[row][col], 1 + dfs(nei_row, nei_col, matrix, memo));
        }

        return memo[row][col];
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
    vector<vector<int>> matrix;

    // 140
    matrix = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {19, 18, 17, 16, 15, 14, 13, 12, 11, 10}, {20, 21, 22, 23, 24, 25, 26, 27, 28, 29}, {39, 38, 37, 36, 35, 34, 33, 32, 31, 30}, {40, 41, 42, 43, 44, 45, 46, 47, 48, 49}, {59, 58, 57, 56, 55, 54, 53, 52, 51, 50}, {60, 61, 62, 63, 64, 65, 66, 67, 68, 69}, {79, 78, 77, 76, 75, 74, 73, 72, 71, 70}, {80, 81, 82, 83, 84, 85, 86, 87, 88, 89}, {99, 98, 97, 96, 95, 94, 93, 92, 91, 90}, {100, 101, 102, 103, 104, 105, 106, 107, 108, 109}, {119, 118, 117, 116, 115, 114, 113, 112, 111, 110}, {120, 121, 122, 123, 124, 125, 126, 127, 128, 129}, {139, 138, 137, 136, 135, 134, 133, 132, 131, 130}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    cout << solution.longestIncreasingPath(matrix) << endl;

    // matrix = {{1}};
    // cout << solution.longestIncreasingPath(matrix) << endl;

    // matrix = {{9, 9, 4},
    //           {6, 6, 8},
    //           {2, 1, 1}};
    // cout << solution.longestIncreasingPath(matrix) << endl;

    // matrix = {{3, 4, 5},
    //           {3, 2, 6},
    //           {2, 2, 1}};
    // cout << solution.longestIncreasingPath(matrix) << endl;

    matrix = {{0, 0, 0, 0, 7},
              {6, 0, 0, 0, 6},
              {5, 4, 3, 4, 5},
              {0, 0, 2, 0, 0},
              {0, 0, 1, 0, 0}};
    cout << solution.longestIncreasingPath(matrix) << endl;
}
