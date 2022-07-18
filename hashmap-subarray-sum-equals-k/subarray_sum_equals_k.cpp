#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    // <prefix_sum_encountered, num_times_prefix_sum_encountered>
    unordered_map<int, int> hashmap;
    // The empty subarray is always an option for every array. It has a prefix sum of 0
    ++hashmap[0];

    int ret = 0;

    int cur_sum = 0;
    for (int& num : nums) {
      cur_sum += num;
      // we just encountered this prefix sum one more time
      if (hashmap.find(cur_sum - k) != hashmap.end()) {
        ret += hashmap[cur_sum - k];
      }
      ++hashmap[cur_sum];
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
  vector<int> nums;
  int k;
  int output;

  nums = {3, 4, 7, 2, -3, 1, 4, 2};
  k = 7;
  output = solution.subarraySum(nums, k);
  cout << output << '\n';
  assert(output == 4);

  cout << "Great success!" << '\n';
}
