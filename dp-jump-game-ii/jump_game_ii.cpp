#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        // Initialize dp, same size as nums, all to the maximum possible jump value
        vector<int> dp(nums.size(), nums.size());
        dp[0] = 0;

        int dp_idx = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (dp_idx == dp.size()) {
                break;
            }

            while (dp_idx <= i + nums[i] && dp_idx < dp.size()) {
                dp[dp_idx] = dp[i] + 1;
                ++dp_idx;
            }
        }

        return dp[dp.size() - 1];
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

    // 2
    nums = {2, 3, 4, 1, 0, 2};
    cout << solution.jump(nums) << '\n';

    // 2
    nums = {2, 3, 1, 1, 4};
    cout << solution.jump(nums) << '\n';

    // 2
    nums = {2, 3, 0, 1, 4};
    cout << solution.jump(nums) << '\n';
}
