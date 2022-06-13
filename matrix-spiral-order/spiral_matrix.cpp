#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int min_row = 0;
        int min_col = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        // right, down, left, up
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirs_idx = 0;
        int cur_row = 0, cur_col = 0;

        vector<int> ret(rows * cols);
        for (int i = 0; i < ret.size(); ++i) {
            int dirs_idx_modded = dirs_idx % dirs.size();
            auto& [dy, dx] = dirs[dirs_idx_modded];

            ret[i] = matrix[cur_row][cur_col];

            if ((cur_row == rows - 1 && dirs_idx_modded == 1) || (cur_col == cols - 1 && dirs_idx_modded == 0) ||
                (cur_row == min_row && dirs_idx_modded == 3) || (cur_col == min_col && dirs_idx_modded == 2)) {
                // Reached the end

                // Change limit
                if (dirs_idx_modded == 0) {
                    // right
                    ++min_row;
                } else if (dirs_idx_modded == 1) {
                    // down
                    --cols;
                } else if (dirs_idx_modded == 2) {
                    // left
                    --rows;
                } else {
                    // up
                    ++min_col;
                }

                // change direction
                ++dirs_idx;
                dirs_idx_modded = dirs_idx % dirs.size();
                auto& [dy, dx] = dirs[dirs_idx_modded];
                cur_row += dy;
                cur_col += dx;
                continue;
            }

            cur_row += dy;
            cur_col += dx;
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
