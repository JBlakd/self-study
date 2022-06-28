#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // binary search for the correct row
        int row = -1;
        int lo = 0;
        int hi = rows - 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) / 2);

            if (matrix[mid][cols - 1] < target) {
                // completely eliminate mid and lower
                // only true if last element of the mid row is smaller than target
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        row = lo;

        // binary search for the correct column
        int col = -1;
        lo = 0;
        hi = cols - 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) / 2);
            if (matrix[row][mid] >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        col = lo;

        return matrix[row][col] == target;
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
    int target;
    bool output;

    matrix = {{3}};
    target = 3;
    output = solution.searchMatrix(matrix, target);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    matrix = {{3}};
    target = 4;
    output = solution.searchMatrix(matrix, target);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    matrix = {{3, 5, 8, 9}};
    target = 4;
    output = solution.searchMatrix(matrix, target);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    matrix = {{3, 5, 8, 9}};
    target = 8;
    output = solution.searchMatrix(matrix, target);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    matrix = {{3}, {5}, {8}, {9}};
    target = 8;
    output = solution.searchMatrix(matrix, target);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    matrix = {{3}, {5}, {8}, {9}};
    target = 4;
    output = solution.searchMatrix(matrix, target);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    target = 13;
    output = solution.searchMatrix(matrix, target);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    target = 3;
    output = solution.searchMatrix(matrix, target);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    cout << "Great success!" << '\n';
}
