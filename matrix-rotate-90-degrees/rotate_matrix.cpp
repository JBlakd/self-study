#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        int temp = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
        matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = matrix[i][j];
        matrix[i][j] = temp;
      }
    }
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
