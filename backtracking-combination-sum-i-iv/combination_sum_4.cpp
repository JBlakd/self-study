#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    // Sort to be able to prune
    sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      dfs(nums, i, target - nums[i], ret);
    }
    return ret;
  }

 private:
  void dfs(vector<int>& nums, int cur_idx, int target, int& ret) {
    // cout << "target: " << target << '\n';
    if (target == 0) {
      ++ret;
      // cout << "ret: " << ret << '\n';
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (target - nums[i] < 0) {
        // break because nums is sorted, and any element beyond nums[i] would be a bust
        break;
      }
      dfs(nums, i, target - nums[i], ret);
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
