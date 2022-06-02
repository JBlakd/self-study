#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // 2d matrix. x axis represents right, y axis represents left
        // Answer will be at dp[multipliers.size()][multipliers.size()]
        vector<vector<int>> dp(multipliers.size() + 1, vector<int>(multipliers.size() + 1, 0));

        // Initialize first row and first col
        for (int i = 1; i <= multipliers.size(); ++i) {
            // horizontal row = right
            dp[0][i] = dp[0][i - 1] + multipliers[i - 1] * nums[nums.size() - i];
            // vertical col = left
            dp[i][0] = dp[i - 1][0] + multipliers[i - 1] * nums[i - 1];
        }

        int ret = max(dp[multipliers.size()][0], dp[0][multipliers.size()]);

        // Populate DP matrix in the same way as the initialization process. But we choose the max of either vertical or horizontal
        for (int i = 1; i <= multipliers.size(); ++i) {
            for (int j = 1; j <= multipliers.size() - i; ++j) {
                // we either got to dp[i][j] from dp[i-1][j] or dp[i][j-1]
                dp[i][j] = max(
                    dp[i - 1][j] + multipliers[i + j - 1] * nums[j - 1],           // coming from the top means we have already chosen j rights
                    dp[i][j - 1] + multipliers[i + j - 1] * nums[nums.size() - i]  // coming from the left means we have already chosen i lefts
                );
            }
            ret = max(ret, dp[i][multipliers.size() - i]);
        }

        for (auto& row : dp) {
            print_vector(row);
            cout << endl;
        }

        return ret;
    }

   private:
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
    vector<int> nums;
    vector<int> multipliers;

    nums = {1, 2, 3};
    multipliers = {3, 2, 1};
    cout << solution.maximumScore(nums, multipliers) << endl;

    nums = {-5, -3, -3, -2, 7, 1};
    multipliers = {-10, -5, 3, 4, 6};
    cout << solution.maximumScore(nums, multipliers) << endl;
}
