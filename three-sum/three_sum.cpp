#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.size() < 3) {
      return ret;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        break; 
      } 

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int j = i + 1;
      int k = nums.size() - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          ret.push_back({nums[i], nums[j], nums[k]});
          // increment j until next unique element found, to avoid duplicates
          do {
            ++j;
          } while (j < k && nums[j] == nums[j - 1]);
        } else if (sum < 0) {
          // too negative, elevate lower threshold
          ++j;
        } else {
          // too positive, decrease upper threshold
          --k;
        }
      }
    }

    return ret;
  }
};

int main() {
  Solution solution;
  vector<int> nums;

  nums = {-1, 0, 1, 2, -1, -4};
  cout << "[";
  for (auto triplet : solution.threeSum(nums)) {
    cout << "[";
    for (int element : triplet) {
      cout << element << ",";
    }
    cout << "],";
  }
  cout << "]\n";
}
