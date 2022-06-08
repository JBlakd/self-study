#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }

        // 2D DP
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
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

    // 1
    cout << solution.uniquePaths(1, 1) << '\n';
    // 28
    cout << solution.uniquePaths(3, 7) << '\n';
    // 3
    cout << solution.uniquePaths(3, 2) << '\n';
}
