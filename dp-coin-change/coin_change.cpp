#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());

        int ret = 0;

        for (int coin : coins) {
            if (coin > amount) {
                continue;
            }

            int num_coins_used = amount / coin;
            ret += num_coins_used;
            amount -= num_coins_used * coin;
        }

        if (amount == 0) {
            return ret;
        } else {
            return -1;
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
