#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int longest_common_subsequence_len = longestCommonSubsequence(word1, word2);

        return (word1.length() - longest_common_subsequence_len) + (word2.length() - longest_common_subsequence_len);
    }

   private:
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

    text1 = "aaaaaaa";
    text2 = "aaaaaa";
    output = solution.minDistance(text1, text2);
    cout << output << '\n';
    assert((output == 1));

    text1 = "a";
    text2 = "c";
    output = solution.minDistance(text1, text2);
    cout << output << '\n';
    assert((output == 2));

    text1 = "leetcode";
    text2 = "etco";
    output = solution.minDistance(text1, text2);
    cout << output << '\n';
    assert((output == 4));

    text1 = "ateco";
    text2 = "ateop";
    output = solution.minDistance(text1, text2);
    cout << output << '\n';
    assert((output == 2));

    text1 = "sea";
    text2 = "eat";
    output = solution.minDistance(text1, text2);
    cout << output << '\n';
    assert((output == 2));

    cout << "Great success!" << '\n';
}
