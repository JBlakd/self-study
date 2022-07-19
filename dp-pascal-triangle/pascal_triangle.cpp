#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret(numRows);
    for (int i = 0; i < numRows; ++i) {
      ret[i].resize(i + 1);
      ret[i][0] = 1;
      ret[i].back() = 1;
    }

    if (numRows <= 2) {
      return ret;
    }

    for (int i = 2; i < numRows; ++i) {
      for (int j = 1; j < ret[i].size() - 1; ++j) {
        ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
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
  int numRows;
  vector<vector<int>> output;

  numRows = 1;
  output = solution.generate(numRows);
  for (auto& row : output) {
    print_vector(row);
    cout << '\n';
  }
  cout << '\n';

  numRows = 2;
  output = solution.generate(numRows);
  for (auto& row : output) {
    print_vector(row);
    cout << '\n';
  }
  cout << '\n';

  numRows = 10;
  output = solution.generate(numRows);
  for (auto& row : output) {
    print_vector(row);
    cout << '\n';
  }
  cout << '\n';

  numRows = 5;
  output = solution.generate(numRows);
  for (auto& row : output) {
    print_vector(row);
    cout << '\n';
  }
  cout << '\n';

  cout << "Great success!" << '\n';
}
