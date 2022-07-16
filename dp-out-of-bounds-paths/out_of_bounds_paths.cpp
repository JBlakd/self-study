#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    rows = m;
    cols = n;
    // each state comprises of the current location (rows, cols) plus moves left. Therefore the state is 3D
    // -1 denotes unvisited state
    vector<vector<vector<uint64_t>>> dp(rows, vector<vector<uint64_t>>(cols, vector<uint64_t>(maxMove + 1, numeric_limits<uint64_t>::max())));
    return (int)(dfs(startRow, startColumn, maxMove, dp) % (1000000007));
  }

 private:
  int rows;
  int cols;
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  uint64_t dfs(int cur_row, int cur_col, int moves_left, vector<vector<vector<uint64_t>>>& dp) {
    // base case, we have reached out of bounds
    if (cur_row < 0 || cur_col < 0 || cur_row >= rows || cur_col >= cols) {
      // we've discovered one way to get out of bounds
      return 1;
    }
    // or we ran out of moves but still in bounds
    if (moves_left == 0) {
      // we've discovered not a way to get out of bounds
      return 0;
    }
    // or we've reached a previously visited and memoized state
    if (dp[cur_row][cur_col][moves_left] != numeric_limits<uint64_t>::max()) {
      return dp[cur_row][cur_col][moves_left];
    }

    // visit neighbours, adding the answer from each neighbour to the current state's memo
    dp[cur_row][cur_col][moves_left] = 0;
    for (auto& [dy, dx] : dirs) {
      dp[cur_row][cur_col][moves_left] += dfs(cur_row + dy, cur_col + dx, moves_left - 1, dp) % (1000000007);
    }

    // after we visited all the neighbours, we have calculated and memoized the answer for the current state and we can return it
    return dp[cur_row][cur_col][moves_left];
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
  int m;
  int n;
  int maxMove;
  int startRow;
  int startColumn;
  int output;

  m = 30;
  n = 24;
  maxMove = 23;
  startRow = 26;
  startColumn = 12;
  output = solution.findPaths(m, n, maxMove, startRow, startColumn);
  cout << output << '\n';
  assert(output == 355074438);

  m = 36;
  n = 5;
  maxMove = 50;
  startRow = 15;
  startColumn = 3;
  output = solution.findPaths(m, n, maxMove, startRow, startColumn);
  cout << output << '\n';
  assert(output == 390153306);

  m = 2;
  n = 2;
  maxMove = 2;
  startRow = 0;
  startColumn = 0;
  output = solution.findPaths(m, n, maxMove, startRow, startColumn);
  cout << output << '\n';
  assert(output == 6);

  m = 8;
  n = 50;
  maxMove = 23;
  startRow = 5;
  startColumn = 26;
  output = solution.findPaths(m, n, maxMove, startRow, startColumn);
  cout << output << '\n';
  assert(output == 914783380);

  cout << "Great success!" << '\n';
}
