#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// #worksfirsttime

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> ret(rows, vector<int>(cols, 0));

    // for every row[0]
    for (int row = 0; row < rows; ++row) {
      priority_queue<int> pq;
      int i = row;
      int j = 0;

      // sorting
      while (i < rows && j < cols) {
        pq.emplace(mat[i][j]);
        ++i;
        ++j;
      }

      // placing back in sorted order
      --i;
      --j;
      while (i >= 0 && j >= 0) {
        ret[i][j] = pq.top();
        pq.pop();
        --i;
        --j;
      }
    }

    // for every col[0]
    for (int col = 1; col < cols; ++col) {
      priority_queue<int> pq;
      int i = 0;
      int j = col;

      // sorting
      while (i < rows && j < cols) {
        pq.emplace(mat[i][j]);
        ++i;
        ++j;
      }

      // placing back in sorted order
      --i;
      --j;
      while (i >= 0 && j >= 0) {
        ret[i][j] = pq.top();
        pq.pop();
        --i;
        --j;
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
