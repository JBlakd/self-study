#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    vector<vector<int>> dp(multipliers.size() + 1, vector<int>(multipliers.size() + 1, 0));

    int m = multipliers.size();
    int n = nums.size();
    for (int op = m - 1; op >= 0; op--) {
      for (int left = op; left >= 0; left--) {
        dp[op][left] = max(multipliers[op] * nums[left] + dp[op + 1][left + 1],
                           multipliers[op] * nums[n - 1 - (op - left)] + dp[op + 1][left]);
      }
    }

    return dp[0][0];
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
  vector<int> nums;
  vector<int> multipliers;
  int output;

  nums = {-5, -3, -3, -2, 7, 1};
  multipliers = {-10, -5, 3, 4, 6};
  output = solution.maximumScore(nums, multipliers);
  cout << output << '\n';
  assert(output == 102);

  cout << "Great success!" << '\n';
}
