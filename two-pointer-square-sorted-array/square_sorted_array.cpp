#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    // find left and right indices
    int left_index = -1;
    int right_index = -1;
    for (int i = 0; i < nums.size(); i++) {
      // if not last element
      if (i != nums.size() - 1) {
        if (nums[i] * nums[i] < nums[i + 1] * nums[i + 1]) {
          left_index = i;
          right_index = i + 1;
          break;
        } else {
          continue;
        }
      } else {
        // left index is last element
        left_index = i;
        right_index = i + 1;
      }
    }

    // Debug printing for previous part
    // for (auto num : nums) {
    //   cout << num << " ";
    // }
    // cout << endl;
    // cout << "left_index: " << left_index << endl;
    // cout << "right_index: " << right_index << endl << endl;

    vector<int> ret;
    while (left_index > -1 || right_index < nums.size()) {
      if (left_index == -1 && right_index != nums.size()) {
        // left_index done, right_index not done
        ret.push_back(nums[right_index] * nums[right_index]);
        ++right_index;
      } else if (left_index != -1 && right_index == nums.size()) {
        // right_index done, left_index not done
        ret.push_back(nums[left_index] * nums[left_index]);
        --left_index;
      } else if (left_index != -1 && right_index != nums.size()) {
        // both indices not done
        if (nums[left_index] * nums[left_index] <= nums[right_index] * nums[right_index]) {
          ret.push_back(nums[left_index] * nums[left_index]);
          --left_index;
        } else {
          ret.push_back(nums[right_index] * nums[right_index]);
          ++right_index;
        }
      }
      // else both indices done, while loop finishes
    }

    return ret;
  }
};

int main() {
  Solution solution;
  vector<int> ret;
  vector<int> nums;

  nums = {-4, -3, -3};
  ret = solution.sortedSquares(nums);
  for (auto val : ret) {
    cout << val << ", ";
  }
  cout << endl;

  nums = {-4, -4, -3};
  ret = solution.sortedSquares(nums);
  for (auto val : ret) {
    cout << val << ", ";
  }
  cout << endl;

  nums = {-4, -1, 0, 3, 10};
  ret = solution.sortedSquares(nums);
  for (auto val : ret) {
    cout << val << ", ";
  }
  cout << endl;

  nums = {-4, -1, 1, 2};
  ret = solution.sortedSquares(nums);
  for (auto val : ret) {
    cout << val << ", ";
  }
  cout << endl;

  nums = {-4, -3, -2, -1};
  ret = solution.sortedSquares(nums);
  for (auto val : ret) {
    cout << val << ", ";
  }
  cout << endl;
}
