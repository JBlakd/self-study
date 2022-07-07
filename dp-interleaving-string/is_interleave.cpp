#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        // if (abs((int)s1.length() - (int)s2.length()) > 1) {
        //     return false;
        // }

        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        // 2D dp. s1 and s2 will have their respective "snake head" which explores the matrix
        // length + 1 to represent the empty substring
        int rows = s1.length() + 1;
        int cols = s2.length() + 1;
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        queue<pair<int, int>> heads;
        heads.emplace(0, 0);

        for (int i = 0; i < s3.length(); ++i) {
            int num_heads = heads.size();
            for (int j = 0; j < num_heads; ++j) {
                int& row = heads.front().first;
                int& col = heads.front().second;
                // down
                if (row < rows && s3[i] == s1[row]) {
                    dp[row + 1][col] = i;
                    heads.emplace(row + 1, col);
                }
                // right
                if (col < cols && s3[i] == s2[col]) {
                    dp[row][col + 1] = i;
                    heads.emplace(row, col + 1);
                }

                heads.pop();
            }

            if (dp[s1.length()][s2.length()] == s3.length() - 1) {
                return true;
            } else if (heads.empty()) {
                return false;
            }
        }

        return true;
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
    string s1;
    string s2;
    string s3;
    bool output;

    s1 = "";
    s2 = "abc";
    s3 = "abc";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    s1 = "a";
    s2 = "b";
    s3 = "a";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    s1 = "a";
    s2 = "";
    s3 = "c";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    s1 = "a";
    s2 = "";
    s3 = "";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    s1 = "a";
    s2 = "";
    s3 = "a";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    s1 = "";
    s2 = "";
    s3 = "a";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    s1 = "";
    s2 = "";
    s3 = "";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbbaccc";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    cout << "Great success!" << '\n';
}
