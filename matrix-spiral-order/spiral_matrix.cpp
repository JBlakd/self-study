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
        int max_row = matrix.size() - 1;
        int max_col = matrix[0].size() - 1;

        // right, down, left, up
        string dirs = "rdlu";
        int cur_dir = 0;

        int i = 0;
        vector<int> ret((max_row + 1) * (max_col + 1));

        while (i < ret.size()) {
            if (dirs[cur_dir % dirs.length()] == 'r') {
                // traverse right
                for (int col = min_col; col <= max_col; ++col) {
                    ret[i] = matrix[min_row][col];
                    ++i;
                }
                // modify limit
                ++min_row;
            } else if (dirs[cur_dir % dirs.length()] == 'd') {
                // traverse down
                for (int row = min_row; row <= max_row; ++row) {
                    ret[i] = matrix[row][max_col];
                    ++i;
                }
                // modify limit
                --max_col;
            } else if (dirs[cur_dir % dirs.length()] == 'l') {
                // traverse left
                for (int col = max_col; col >= min_col; --col) {
                    ret[i] = matrix[max_row][col];
                    ++i;
                }
                // modify limit
                --max_row;
            } else {
                // traverse up
                for (int row = max_row; row >= min_row; --row) {
                    ret[i] = matrix[row][min_col];
                    ++i;
                }
                // modify limit
                ++min_col;
            }

            // change directions
            ++cur_dir;
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
