#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // right,       down,         left,        up
        // it is a non-inclusive limit
        vector<int> limits = {cols, rows, -1, -1};
        int limits_idx = 0;
        int cur_row = 0, cur_col = 0;

        vector<int> ret(rows * cols);
        for (int i = 0; i < ret.size(); ++i) {
            int limits_idx_trimmed = limits_idx % limits.size();
            int limit = limits[limits_idx_trimmed];
            if (limits_idx_trimmed == 0) {
                // right
                if (cur_col == limit - 1) {
                    // alter limit of previous direction
                    ++limits[3];
                    ++limits_idx;
                    ret[i] = matrix[cur_row][cur_col];
                    ++cur_row;
                    continue;
                }

                ret[i] = matrix[cur_row][cur_col];
                ++cur_col;
            } else if (limits_idx_trimmed == 1) {
                // down
                if (cur_row == limit - 1) {
                    // alter limit of previous direction
                    --limits[0];
                    ++limits_idx;
                    ret[i] = matrix[cur_row][cur_col];
                    --cur_col;
                    continue;
                }

                ret[i] = matrix[cur_row][cur_col];
                ++cur_row;
            } else if (limits_idx_trimmed == 2) {
                // left
                if (cur_col == limit + 1) {
                    // alter limit of previous direction
                    --limits[1];
                    ++limits_idx;
                    ret[i] = matrix[cur_row][cur_col];
                    --cur_row;
                    continue;
                }

                ret[i] = matrix[cur_row][cur_col];
                --cur_col;
            } else {
                // up
                if (cur_row == limit + 1) {
                    // alter limit of previous direction
                    --limits[2];
                    ++limits_idx;
                    ret[i] = matrix[cur_row][cur_col];
                    ++cur_col;
                    continue;
                }

                ret[i] = matrix[cur_row][cur_col];
                --cur_row;
            }
        }

        return ret;
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
    vector<int> output;

    matrix = {{1, 2, 3, 4, 5},
              {6, 7, 8, 9, 10},
              {11, 12, 13, 14, 15},
              {16, 17, 18, 19, 20},
              {21, 22, 23, 24, 25}};
    output = solution.spiralOrder(matrix);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{1, 2, 3, 4, 5, 10, 15, 20, 25, 24, 23, 22, 21, 16, 11, 6, 7, 8, 9, 14, 19, 18, 17, 12, 13}));

    matrix = {{-69}};
    output = solution.spiralOrder(matrix);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{-69}));

    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    output = solution.spiralOrder(matrix);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5}));

    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    output = solution.spiralOrder(matrix);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));

    cout << "Great success!" << '\n';
}
