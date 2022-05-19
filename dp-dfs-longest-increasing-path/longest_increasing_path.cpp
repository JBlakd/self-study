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

        // 2D memo matrix storing length of longest increasing path starting from the current coordinate
        vector<vector<int>> memo(rows, vector<int>(cols, -1));

        int ret = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                vector<vector<int>> neis = calc_neis(i, j, memo, matrix);

                // If there is a reachable, already-memoized neighbour, then we immediately know the current location's answer, and no need to visit any other neighbours
                // The current location's answer is the maximum neighbour's memo + 1
                int max_nei_memo = -1;
                for (auto nei : neis) {
                    max_nei_memo = max(max_nei_memo, memo[nei[0]][nei[1]]);
                }
                if (max_nei_memo != -1 && max_nei_memo != -2) {
                    memo[i][j] = max_nei_memo + 1;
                    continue;
                }

                if (memo[i][j] == -1) {
                    int i_j_max_length = 1;
                    dfs(i, j, 1, i_j_max_length, memo, matrix);
                    ret = max(memo[i][j], ret);
                }
            }
        }

        return ret;
    }

   private:
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int rows;
    int cols;

    // find longest increasing path length from matrix[row][col]
    void dfs(int row, int col, int cur_length, int& max_length, vector<vector<int>>& memo, vector<vector<int>>& matrix) {
        // calculate neighbours
        vector<vector<int>> neis = calc_neis(row, col, memo, matrix);
        // base case, return if no neighbours
        if (neis.empty()) {
            if (cur_length > max_length) {
                max_length = cur_length;
            }
            // callback
            memo[row][col] = max_length - cur_length + 1;
            return;
        }

        // visit. memo[row][col] == -2 denotes visited
        memo[row][col] = -2;

        // If there are no memoized neighbours, recurse neighbours
        for (auto nei : neis) {
            dfs(nei[0], nei[1], cur_length + 1, max_length, memo, matrix);
        }

        // callback
        memo[row][col] = max_length - cur_length + 1;
    }

    vector<vector<int>> calc_neis(int row, int col, vector<vector<int>>& memo, vector<vector<int>>& matrix) {
        vector<vector<int>> neis;
        for (auto dir : dirs) {
            int nei_row = row + dir[0];
            int nei_col = col + dir[1];
            // reject if visited or out of bounds or not increasing
            if (nei_row < 0 || nei_col < 0 || nei_row >= rows || nei_col >= cols || memo[nei_row][nei_col] == -2 || matrix[nei_row][nei_col] <= matrix[row][col]) {
                continue;
            }
            neis.push_back({nei_row, nei_col});
        }
        return neis;
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

    // // 140
    // matrix = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {19, 18, 17, 16, 15, 14, 13, 12, 11, 10}, {20, 21, 22, 23, 24, 25, 26, 27, 28, 29}, {39, 38, 37, 36, 35, 34, 33, 32, 31, 30}, {40, 41, 42, 43, 44, 45, 46, 47, 48, 49}, {59, 58, 57, 56, 55, 54, 53, 52, 51, 50}, {60, 61, 62, 63, 64, 65, 66, 67, 68, 69}, {79, 78, 77, 76, 75, 74, 73, 72, 71, 70}, {80, 81, 82, 83, 84, 85, 86, 87, 88, 89}, {99, 98, 97, 96, 95, 94, 93, 92, 91, 90}, {100, 101, 102, 103, 104, 105, 106, 107, 108, 109}, {119, 118, 117, 116, 115, 114, 113, 112, 111, 110}, {120, 121, 122, 123, 124, 125, 126, 127, 128, 129}, {139, 138, 137, 136, 135, 134, 133, 132, 131, 130}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    // cout << solution.longestIncreasingPath(matrix) << endl;

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
