#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // vector size has to be amount + 1, because the last index must be amount
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;

        // Useful for the start index of the loop
        // sort(coins.begin(), coins.end());
        // Make sure the start index of the loop will result in dp having the first valid value

        for (int i = 1; i <= amount; ++i) {
            int min_prev_coins = 10001;
            for (int coin_val : coins) {
                if (i - coin_val < 0 || dp[i - coin_val] == 10002) {
                    continue;
                }

                if (dp[i - coin_val] < min_prev_coins) {
                    min_prev_coins = dp[i - coin_val];
                }
            }
            // If no valid coins found, then dp[i] = 10002
            dp[i] = min_prev_coins + 1;
        }

        if (dp[amount] == 10002) {
            return -1;
        }
        return dp[amount];
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
    vector<int> coins;
    int amount;

    // 20
    coins = {186, 419, 83, 408};
    amount = 6249;
    cout << solution.coinChange(coins, amount) << endl;

    // -1
    coins = {10, 7, 3};
    amount = 35;
    cout << solution.coinChange(coins, amount) << endl;

    // 5
    coins = {10, 7, 5, 2, 1};
    amount = 33;
    cout << solution.coinChange(coins, amount) << endl;

    // 3
    coins = {1, 2, 5};
    amount = 11;
    cout << solution.coinChange(coins, amount) << endl;

    // -1
    coins = {2};
    amount = 3;
    cout << solution.coinChange(coins, amount) << endl;

    // 0
    coins = {1};
    amount = 0;
    cout << solution.coinChange(coins, amount) << endl;
}
