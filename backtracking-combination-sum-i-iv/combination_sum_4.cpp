#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    // this a DP problem mane
    sort(nums.begin(), nums.end());

    // initialise dp array, target from index 0 to index target
    vector<uint32_t> dp(target + 1, 0);
    // the empty array is the sole way to form a target of 0
    dp[0] = 1;
    for (int cur_target = 1; cur_target <= target; ++cur_target) {
      // for each target value, explore each num
      for (int& num : nums) {
        // but only if it's smaller or equal to the target
        if (num > cur_target) {
          break;
        }

        dp[cur_target] += dp[cur_target - num];
      }
    }

    return (int)dp[target];
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
  int target;
  int output;

  nums = {1, 2, 3};
  target = 32;
  output = solution.combinationSum4(nums, target);
  cout << output << '\n';
  assert(output == 181997601);

  nums = {2, 3, 1};
  target = 4;
  output = solution.combinationSum4(nums, target);
  cout << output << '\n';
  assert(output == 7);

  cout << "Great success!" << '\n';
}
