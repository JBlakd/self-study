#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    if (k == 0 || prices.size() == 0) {
      return 0;
    }

    vector<int> dp(prices.size(), 0);
    int ret = 0;

    while (k > 0) {
      // initial position is buying the stock on the first day
      int pos = prices[0] * -1;
      // initial profit is buying the stock and then selling it immediately for net zero profit
      dp[0] = 0;

      for (int i = 1; i < prices.size(); ++i) {
        // today's position is the better of the previous day's position or buying today's stock using the profit so far
        pos = max(pos, dp[i] - prices[i]);
        // today's profit is the better of yesterday's profits or being at current position and selling at today's prices
        dp[i] = max(dp[i - 1], pos + prices[i]);
        // record maximum profit
        ret = max(ret, dp[i]);
      }

      --k;
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
