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

    // start at the first element of the largest row
    int row = rows - 1;
    int col = 0;

    while (row >= 0 && row < rows && col >= 0 && col < cols) {
      if (matrix[row][col] == target) {
        return true;
      }

      if (matrix[row][col] > target) {
        --row;
      } else {
        ++col;
      }
    }

    return false;
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
