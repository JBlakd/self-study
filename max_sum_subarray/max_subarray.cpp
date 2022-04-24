// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    int i = 1;
    int max_ending_here = nums[0];
    int max_so_far = nums[0];

    while (i < nums.size()) {
      if (nums[i] > (max_ending_here + nums[i])) {
        max_ending_here = nums[i];
      } else {
        max_ending_here += nums[i];
      }

      if (max_ending_here > max_so_far) {
        max_so_far = max_ending_here;
      }

      i++;
    }

    return max_so_far;
  }
};

int main() {
  Solution solution;
  vector<int> input;

  input = {1, 2};
  cout << solution.maxSubArray(input) << endl;

  input = {5, 4, -1, 7, 8};
  cout << solution.maxSubArray(input) << endl;

  input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << solution.maxSubArray(input) << endl;
}
