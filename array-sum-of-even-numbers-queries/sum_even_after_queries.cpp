#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ret(queries.size());

    int even_sum = 0;
    for (int& num : nums) {
      if (num % 2 == 0) {
        even_sum += num;
      }
    }

    for (int i = 0; i < queries.size(); ++i) {
      int num_before = nums[queries[i][1]];
      nums[queries[i][1]] += queries[i][0];

      if (num_before % 2 == 0) {
        // from even
        if (nums[queries[i][1]] % 2 == 0) {
          // to even
          even_sum += queries[i][0];
        } else {
          // to odd
          even_sum -= num_before;
        }
      } else {
        // from odd
        if (nums[queries[i][1]] % 2 == 0) {
          // to even
          even_sum += nums[queries[i][1]];
        }
      }

      ret[i] = even_sum;
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
