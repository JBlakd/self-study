#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    // Intuition: the only way we could've reached the step we're at
    // is from the step before the current one
    // or the step twice before the current one
   public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
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
}
