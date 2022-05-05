// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        // Sliding resizeable window
        int left_index = 0;
        int right_index = 1;
        int max_profit = 0;
        while (right_index < prices.size()) {
            if (prices[right_index] < prices[left_index]) {
                left_index = right_index;
            } else {
                if (prices[right_index] - prices[left_index] > max_profit) {
                    max_profit = prices[right_index] - prices[left_index];
                }
            }
            right_index++;
        }

        return max_profit;
    }
};

int main() {
    Solution solution;
    vector<int> input;

    input = {2, 4, 1};
    cout << solution.maxProfit(input) << endl;

    input = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(input) << endl;

    input = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(input) << endl;
}
