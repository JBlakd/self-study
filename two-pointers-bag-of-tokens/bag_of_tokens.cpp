#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int lo = 0;
    int hi = tokens.size() - 1;
    int ret = 0;
    while (lo <= hi) {
      if (power >= tokens[lo]) {
        power -= tokens[lo];
        ++lo;
        ++ret;
      } else if (ret > 0 && lo < hi) {
        // only play face down if there's a possibility of a net gain
        power += tokens[hi];
        --hi;
        --ret;
      } else {
        break;
      }
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
  vector<int> tokens;
  int power;
  int output;

  tokens = {6, 0, 39, 52, 45, 49, 59, 68, 42, 37};
  power = 99;
  output = solution.bagOfTokensScore(tokens, power);
  cout << output << '\n';
  assert(output == 5);

  tokens = {71, 55, 82};
  power = 54;
  output = solution.bagOfTokensScore(tokens, power);
  cout << output << '\n';
  assert(output == 0);

  tokens = {100, 200, 300, 400};
  power = 200;
  output = solution.bagOfTokensScore(tokens, power);
  cout << output << '\n';
  assert(output == 2);

  cout << "Great success!" << '\n';
}
