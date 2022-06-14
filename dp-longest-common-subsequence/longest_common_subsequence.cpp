#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.length();
        int cols = text2.length();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        // initialise bottom-right corner
        dp[rows - 1][cols - 1] = (text1.back() == text2.back()) ? 1 : 0;

        // Initialize bottom row
        for (int col = cols - 2; col >= 0; --col) {
            if (text2[col] == text1[rows - 1]) {
                dp[rows - 1][col] = 1;
            } else {
                dp[rows - 1][col] = (dp[rows - 1][col + 1] == 1) ? 1 : 0;
            }
        }
        // Initialize right-most column
        for (int row = rows - 2; row >= 0; --row) {
            if (text1[row] == text2[cols - 1]) {
                dp[row][cols - 1] = 1;
            } else {
                dp[row][cols - 1] = (dp[row + 1][cols - 1] == 1) ? 1 : 0;
            }
        }

        // Reverse zigzag
        for (int row = rows - 2; row >= 0; --row) {
            for (int col = cols - 2; col >= 0; --col) {
                if (text1[row] == text2[col]) {
                    // if match
                    dp[row][col] = 1 + dp[row + 1][col + 1];
                } else {
                    dp[row][col] = max(dp[row + 1][col], dp[row][col + 1]);
                }
            }
        }

        return dp[0][0];
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
    string text1, text2;
    int output;

    text1 = "bradda";
    text2 = "bedding";
    output = solution.longestCommonSubsequence(text1, text2);
    cout << output << '\n';
    assert((output == 3));

    text1 = "abcde";
    text2 = "ace";
    output = solution.longestCommonSubsequence(text1, text2);
    cout << output << '\n';
    assert((output == 3));

    text1 = "abc";
    text2 = "abc";
    output = solution.longestCommonSubsequence(text1, text2);
    cout << output << '\n';
    assert((output == 3));

    text1 = "abc";
    text2 = "def";
    output = solution.longestCommonSubsequence(text1, text2);
    cout << output << '\n';
    assert((output == 0));

    cout << "Great success!" << '\n';
}
