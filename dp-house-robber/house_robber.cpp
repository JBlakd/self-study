#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        // intuition: It only makes sense for the robber to skip 1 house or skip 2 houses
        // Therefore, to get to where I am now, I must have been previously 2 houses away or 3 houses away
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];

        for (int i = 3; i < dp.size(); ++i) {
            dp[i] = max(
                nums[i] + dp[i - 2],
                nums[i] + dp[i - 3]);
        }

        return -1;
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
