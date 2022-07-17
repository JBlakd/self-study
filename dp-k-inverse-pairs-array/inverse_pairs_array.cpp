#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int kInversePairs(int n, int k) {
    if (k == 0) {
      return 1;
    }

    if (n == 1) {
      return 0;
    }

    // 2 rows only, to optimize space
    vector<vector<uint64_t>> dp(2, vector<uint64_t>(k + 1, 0));

    // initialize DP
    dp[1][0] = 1;

    for (int i = 2; i <= n; ++i) {
      int row = i % 2;
      int prev_row = (i - 1) % 2;
      dp[row][0] = 1;
      for (int col = 1; col <= k; ++col) {
        // window_size == i
        dp[row][col] = dp[row][col - 1];
        if (col < i) {
          // still building until the window size
          dp[row][col] += dp[prev_row][col];
        } else {
          // sliding window: subtract the term left behind
          dp[row][col] -= dp[prev_row][col - i];
          // sliding window: add the term newly discovered
          dp[row][col] += dp[prev_row][col];

          // nothing else nonzero to discover
          if (dp[row][col] == 0) {
            break;
          }
        }

        dp[row][col] = (dp[row][col] + 1000000007ULL) % 1000000007ULL;
      }
    }

    return (int)(dp[n % 2][k]);
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
  int n;
  int k;
  int output;

  n = 20;
  k = 20;
  output = solution.kInversePairs(n, k);
  cout << output << '\n';
  assert(output == 106447125);

  n = 500;
  k = 500;
  output = solution.kInversePairs(n, k);
  cout << output << '\n';
  assert(output == 334048938);

  n = 1000;
  k = 1000;
  output = solution.kInversePairs(n, k);
  cout << output << '\n';
  assert(output == 663677020);

  n = 5;
  k = 5;
  output = solution.kInversePairs(n, k);
  cout << output << '\n';
  assert(output == 22);

  cout << "Great success!" << '\n';
}
