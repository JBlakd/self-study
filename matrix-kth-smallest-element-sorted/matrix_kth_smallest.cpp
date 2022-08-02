#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    rows = matrix.size();
    cols = matrix[0].size();

    int lo = matrix[0][0];
    int hi = matrix[rows - 1][cols - 1];

    while (true) {
      if (hi == lo) {
        return lo;
      }

      int mid = lo + (hi - lo) / 2;
      auto [cnt, largest] = count_smaller(mid, matrix);
      if (cnt > k) {
        hi = mid;
      } else if (cnt < k) {
        lo = mid + 1;
      } else {
        return largest;
      }
    }

    return -1;
  }

 private:
  int rows;
  int cols;

  pair<int, int> count_smaller(int num, vector<vector<int>>& matrix) {
    int cnt = 0;
    int largest = numeric_limits<int>::min();
    int col_idx = cols - 1;

    for (vector<int>& row : matrix) {
      if (row[0] > num) {
        break;
      }

      while (row[col_idx] > num) {
        --col_idx;
      }

      cnt += (col_idx + 1);
      largest = max(largest, row[col_idx]);
    }

    return {cnt, largest};
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
  int k;
  int output;

  matrix = {
      {1, 2},
      {1, 3}};
  k = 4;
  output = solution.kthSmallest(matrix, k);
  cout << output << '\n';
  assert(output == 3);

  matrix = {
      {1, 1, 1},
      {1, 1, 1},
      {1, 1, 1}};
  k = 1;
  output = solution.kthSmallest(matrix, k);
  cout << output << '\n';
  assert(output == 1);

  matrix = {
      {1, 3, 7},
      {5, 10, 12},
      {6, 10, 15}};
  k = 3;
  output = solution.kthSmallest(matrix, k);
  cout << output << '\n';
  assert(output == 5);

  cout << "Great success!" << '\n';
}
