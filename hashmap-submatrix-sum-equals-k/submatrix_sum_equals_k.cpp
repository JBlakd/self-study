#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    rows = matrix.size();
    cols = matrix[0].size();

    // generate prefix matrix
    vector<vector<int>> prefix(rows, vector<int>(cols, 0));
    prefix[0][0] = matrix[0][0];
    for (int i = 1; i < cols; ++i) {
      prefix[0][i] = prefix[0][i - 1] + matrix[0][i];
    }
    for (int i = 1; i < rows; ++i) {
      prefix[i][0] = prefix[i - 1][0] + matrix[i][0];
    }
    for (int row = 1; row < rows; ++row) {
      for (int col = 1; col < cols; ++col) {
        prefix[row][col] = prefix[row][col - 1] + prefix[row - 1][col] + matrix[row][col] - prefix[row - 1][col - 1];
      }
    }

    if (rows > cols) {
      return linear_cols(prefix, target);
    } else {
      return linear_rows(prefix, target);
    }
  }

 private:
  int rows;
  int cols;

  int linear_rows(vector<vector<int>>& prefix, int target) {
    int ret = 0;

    for (int start_row = 0; start_row < rows; ++start_row) {
      for (int end_row = start_row; end_row < rows; ++end_row) {
        unordered_map<int, int> hashmap;
        ++hashmap[0];

        int cur_sum = 0;
        for (int col = 0; col < cols; ++col) {
          // Calculate cur_sum
          cur_sum = prefix[end_row][col];
          if (start_row != 0) {
            cur_sum -= prefix[start_row - 1][col];
          }

          if (hashmap.find(cur_sum - target) != hashmap.end()) {
            ret += hashmap[cur_sum - target];
          }
          ++hashmap[cur_sum];
        }
      }
    }
    return ret;
  }

  int linear_cols(vector<vector<int>>& prefix, int target) {
    int ret = 0;

    for (int start_col = 0; start_col < cols; ++start_col) {
      for (int end_col = start_col; end_col < cols; ++end_col) {
        unordered_map<int, int> hashmap;
        ++hashmap[0];

        int cur_sum = 0;
        for (int row = 0; row < rows; ++row) {
          // Calculate cur_sum
          cur_sum = prefix[row][end_col];
          if (start_col != 0) {
            cur_sum -= prefix[row][start_col - 1];
          }

          if (hashmap.find(cur_sum - target) != hashmap.end()) {
            ret += hashmap[cur_sum - target];
          }
          ++hashmap[cur_sum];
        }
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
  int target;
  int output;

  matrix = {{10, 20, 30},
            {5, 10, 20},
            {2, 4, 6}};
  target = 7;
  output = solution.numSubmatrixSumTarget(matrix, target);

  cout << "Great success!" << '\n';
}
