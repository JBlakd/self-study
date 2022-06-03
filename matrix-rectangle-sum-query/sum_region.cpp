#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NumMatrix {
   public:
    NumMatrix(vector<vector<int>>& matrix) : rows(matrix.size()), cols(matrix[0].size()) {
        sum_matrix.resize(rows, vector<int>(cols));

        // calculate sum_matrix
        // Firstly iterate top left to bottom right, each element being the sum of its current row so far
        for (int i = 0; i < rows; ++i) {
            int row_sum = 0;
            for (int j = 0; j < cols; ++j) {
                row_sum += matrix[i][j];
                sum_matrix[i][j] = row_sum;
            }
        }

        // Then use the info to calculate the sum of the square with top-left corner at (0,0) and bottom-right corner at (i,j)
        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == 0) {
                    sum_matrix[i][j] = sum_matrix[i - 1][j] + matrix[i][j];
                } else {
                    sum_matrix[i][j] = sum_matrix[i - 1][j] + sum_matrix[i][j - 1] + matrix[i][j] - sum_matrix[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // biggest region
        int ret = sum_matrix[row2][col2];

        if (col1 != 0) {
            // unwanted region left of the wanted region
            ret -= sum_matrix[row2][col1 - 1];
        }

        if (row1 != 0) {
            // unwanted region above the wanted region
            ret -= sum_matrix[row1 - 1][col2];
        }

        // Adding back the doubly-subtracted region diagonally (top-left) adjacent to the wanted region
        // Double subtraction only happens if both of the above if-statements are evaluated
        if (row1 != 0 && col1 != 0) {
            ret += sum_matrix[row1 - 1][col1 - 1];
        }

        return ret;
    }

    vector<vector<int>>& get_sum_matrix() {
        return sum_matrix;
    }

   private:
    int rows;
    int cols;
    vector<vector<int>> sum_matrix;
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
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
                                  {1, 0, 3, 0, 5}};
    NumMatrix numMatrix(matrix);

    // for (auto& row : numMatrix.get_sum_matrix()) {
    //     print_vector(row);
    //     cout << '\n';
    // }
    // cout << '\n';

    // 3
    cout << numMatrix.sumRegion(0, 0, 0, 0) << endl;
    // 8
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    // 11
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
    // 12
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
    // 5
    cout << numMatrix.sumRegion(4, 4, 4, 4) << endl;

    matrix = {{6}};
    numMatrix = NumMatrix(matrix);

    // 6
    cout << numMatrix.sumRegion(0, 0, 0, 0) << endl;
}
