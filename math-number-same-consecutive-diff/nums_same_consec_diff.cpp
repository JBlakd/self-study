#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> numsSameConsecDiff(int n, int k) {
    // num_ascend == 9 - k, num_descend = 10 - k
    // num_numbers = 19 - 2k
    int nums_size = (k == 0) ? 9 : 19 - 2 * k;
    vector<string> nums(nums_size, string(n, '?'));
    // nums index
    int i = 0;

    // ascending
    for (int start_digit = 1; start_digit <= 9 - k; ++start_digit) {
      nums[i][0] = '0' + start_digit;
      nums[i][1] = '0' + start_digit + k;
      // populating the rest of the string
      for (int j = 2; j < nums[i].length(); ++j) {
        nums[i][j] = nums[i][j - 2];
      }
      ++i;
    }

    if (k != 0) {
      // descending
      for (int start_digit = k; start_digit < 10; ++start_digit) {
        nums[i][0] = '0' + start_digit;
        nums[i][1] = '0' + start_digit - k;
        // populating the rest of the string
        for (int j = 2; j < nums[i].length(); ++j) {
          nums[i][j] = nums[i][j - 2];
        }
        ++i;
      }
    }

    vector<int> ret(nums.size());
    for (int j = 0; j < ret.size(); ++j) {
      ret[j] = stoi(nums[j], nullptr, 10);
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
  vector<int> output;

  output = solution.numsSameConsecDiff(2, 1);

  output = solution.numsSameConsecDiff(3, 7);

  cout << "Great success!" << '\n';
}
