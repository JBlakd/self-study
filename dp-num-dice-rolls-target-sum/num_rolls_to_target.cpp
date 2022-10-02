#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numRollsToTarget(int n, int k, int target) {
    if (n == 1) {
      if (target <= k) {
        return 1;
      }
      return 0;
    }

    // vector<vector<int64_t>> dp(2, vector<int64_t>(target + 1, 0));
    int64_t dp[2][1001];
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j <= 1000; ++j) {
        dp[i][j] = 0;
      }
    }

    // initialise 1 die row
    for (int i = 1; i <= k; ++i) {
      dp[1][i] = 1;
    }

    for (int die = 2; die <= n; ++die) {
      // clear cur_targe
      for (int cur_target = 0; cur_target < die; ++cur_target) {
        dp[die % 2][cur_target] = 0;
      }

      for (int cur_target = die; cur_target <= target; ++cur_target) {
        dp[die % 2][cur_target] = dp[die % 2][cur_target - 1] + dp[(die + 1) % 2][cur_target - 1];
        if (cur_target - k - 1 >= 0) {
          dp[die % 2][cur_target] -= dp[(die + 1) % 2][cur_target - k - 1];
          if (dp[die % 2][cur_target] < 0) {
            cout << "fucked up\n";
          }
        }
        dp[die % 2][cur_target] %= 1000000007;
      }
    }

    return (int)dp[n % 2][target];
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
  int target;
  int output;

  // n = 22;
  // k = 3;
  // target = 8;
  // output = solution.numRollsToTarget(n, k, target);
  // cout << output << '\n';
  // assert(output == 0);

  n = 20;
  k = 19;
  target = 233;
  output = solution.numRollsToTarget(n, k, target);
  cout << output << '\n';
  assert(output == 378846878);

  n = 3;
  k = 6;
  target = 15;
  output = solution.numRollsToTarget(n, k, target);
  cout << output << '\n';
  assert(output == 10);

  n = 2;
  k = 4;
  target = 3;
  output = solution.numRollsToTarget(n, k, target);
  cout << output << '\n';
  assert(output == 2);

  n = 2;
  k = 12;
  target = 8;
  output = solution.numRollsToTarget(n, k, target);
  cout << output << '\n';
  assert(output == 7);

  cout << "Great success!" << '\n';
}
