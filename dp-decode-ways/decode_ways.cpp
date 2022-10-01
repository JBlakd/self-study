#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') {
      return 0;
    }

    vector<int> dp(s.length() + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i < s.length(); ++i) {
      bool transition_found = false;

      // check i state transition
      if (s[i] != '0') {
        dp[i + 1] += dp[i];
        transition_found = true;
      }

      // check i-1 state transition
      int two_digit_num = (s[i - 1] - '0') * 10 + (s[i] - '0');
      if (two_digit_num >= 10 && two_digit_num <= 26) {
        dp[i + 1] += dp[i - 1];
        transition_found = true;
      }

      if (!transition_found) {
        return 0;
      }
    }

    return dp.back();
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
