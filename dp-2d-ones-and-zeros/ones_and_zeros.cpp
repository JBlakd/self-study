#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Initialize 2D vector to all zeros. Dimensions 1 bigger than m and n to account for zero case.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // For each string, iterate through the array from bottom-right to top-left
        for (string& str : strs) {
            // First count the number of zeroes and ones in each string
            int num_ones = count(str.begin(), str.end(), '1');
            int num_zeros = str.length() - num_ones;

            for (int zero_row = m; zero_row >= num_zeros; --zero_row) {
                for (int one_col = n; one_col >= num_ones; --one_col) {
                    // Basically, for the current string, superimpose the optimum pick/not-pick choice into the DP
                    dp[zero_row][one_col] = max(dp[zero_row][one_col], dp[zero_row - num_zeros][one_col - num_ones] + 1);
                }
            }
        }

        return dp[m][n];
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
    vector<string> strs;
    int m;
    int n;

    strs = {"10", "0001", "111001", "1", "0"};
    m = 5;
    n = 3;
    cout << solution.findMaxForm(strs, m, n) << endl;
}
