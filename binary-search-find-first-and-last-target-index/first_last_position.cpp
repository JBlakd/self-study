#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>::iterator start = lower_bound(nums.begin(), nums.end(), target);
    if (start == nums.end() || *(start) != target) {
      return {-1, -1};
    }
    vector<int>::iterator end = upper_bound(nums.begin(), nums.end(), target);
    return {static_cast<int>(start - nums.begin()), static_cast<int>(end - nums.begin() - 1)};
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
