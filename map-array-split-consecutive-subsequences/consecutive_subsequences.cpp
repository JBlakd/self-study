#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    // <num, count>
    unordered_map<int, int> hashmap;
    vector<int> keys;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] - nums[i - 1] > 1) {
        // input is invalid
        return false;
      }

      if (keys.empty() || keys.back() != nums[i]) {
        keys.push_back(nums[i]);
      }

      ++hashmap[nums[i]];
    }

    while (true) {
      int prev_valid_key = -1001;
      int subsequence_size = 0;
      bool all_done = true;
      for (int& key : keys) {
        if (hashmap[key] > 0) {
          all_done = false;
          if (prev_valid_key == -1001 || prev_valid_key == key - 1) {
            ++subsequence_size;
            --hashmap[key];
            prev_valid_key = key;
          } else {
            return false;
          }
        }
      }

      if (subsequence_size < 3) {
        return false;
      }

      if (all_done) {
        return true;
      }
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

  nums = {1, 2, 3, 3, 4, 5};
  assert(solution.isPossible(nums) == true);

  cout << "Great success!" << '\n';
}
