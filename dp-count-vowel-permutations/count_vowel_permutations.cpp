#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countVowelPermutation(int n) {
    int end_row = (n + 1) % 2;
    vector<vector<uint64_t>> dp(2, vector<uint64_t>(5, 1));

    while (n > 1) {
      vector<uint64_t>& cur_dp_row = dp[n % 2];
      vector<uint64_t>& prev_dp_row = dp[(n + 1) % 2];
      for (int i = 0; i < 5; ++i) {
        switch (i) {
          case 0:
            cur_dp_row[i] = (prev_dp_row[1] + prev_dp_row[2] + prev_dp_row[4]) % 1000000007;
            break;
          case 1:
            cur_dp_row[i] = (prev_dp_row[0] + prev_dp_row[2]) % 1000000007;
            break;
          case 2:
            cur_dp_row[i] = (prev_dp_row[1] + prev_dp_row[3]) % 1000000007;
            break;
          case 3:
            cur_dp_row[i] = prev_dp_row[2] % 1000000007;
            break;
          case 4:
            cur_dp_row[i] = (prev_dp_row[2] + prev_dp_row[3]) % 1000000007;
            break;
        }
      }
      --n;
    }

    uint64_t ret = 0;
    for (uint64_t& num : dp[0]) {
      ret = (ret + num) % 1000000007;
    }
    return (int)ret;
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
  int output;

  output = solution.countVowelPermutation(20000);
  cout << output << '\n';
  assert(output == 759959057);

  output = solution.countVowelPermutation(4);
  cout << output << '\n';
  assert(output == 35);

  output = solution.countVowelPermutation(5);
  cout << output << '\n';
  assert(output == 68);

  cout << "Great success!" << '\n';
}
