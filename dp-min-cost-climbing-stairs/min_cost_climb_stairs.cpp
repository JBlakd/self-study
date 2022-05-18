#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Build the dp array from the bottom up
        // Try out the cost for taking 1 step versus taking 2 steps
        // populate the dp array using the optimal solution
        vector<int> dp(cost.size() + 1);
        // Can start from step 0 or step 1 for free
        dp[0] = 0;
        dp[1] = 0;
        // loop until we reach the top (the index past the final index)
        for (int i = 2; i <= cost.size(); ++i) {
            // from i - 1            from i-2
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
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
    vector<int> cost;

    cost = {10, 15, 10, 4};
    cout << solution.minCostClimbingStairs(cost) << endl;

    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << solution.minCostClimbingStairs(cost) << endl;
}
