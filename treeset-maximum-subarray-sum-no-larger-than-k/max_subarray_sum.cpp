#include <cassert>
#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int ret = numeric_limits<int>::min();

    for (int row1 = 0; row1 < rows; ++row1) {
      vector<int> rows_summed(cols);
      for (int row2 = row1; row2 < rows; ++row2) {
        for (int col = 0; col < cols; ++col) {
          rows_summed[col] += matrix[row2][col];
        }
        ret = max(ret, max_sum_subarray(rows_summed, k));
      }
    }

    return ret;
  }

 private:
  int max_sum_subarray(vector<int>& arr, int k) {
    set<int> treeset;
    treeset.emplace(0);
    int ret = numeric_limits<int>::min();
    int right = 0;

    for (int& num : arr) {
      right += num;
      auto left = treeset.lower_bound(right - k);
      if (left != treeset.end()) {
        ret = max(ret, right - *(left));
      }
      treeset.emplace(right);
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
