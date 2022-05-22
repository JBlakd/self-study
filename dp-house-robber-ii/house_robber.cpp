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

        return max(robbie_rotten(0, nums.size() - 2, nums), robbie_rotten(1, nums.size() - 1, nums));
    }

   private:
    int robbie_rotten(int start, int end, vector<int>& nums) {
        if (end - start == 0) {
            return nums[start];
        }

        if (end - start == 1) {
            return max(nums[start], nums[end]);
        }

        // intuition: It only makes sense for the robber to skip 1 house or skip 2 houses
        // Therefore, to get to where I am now, I must have been previously 2 houses away or 3 houses away
        vector<int> dp(end - start + 1);
        dp[0] = nums[start];
        dp[1] = nums[start + 1];
        dp[2] = dp[0] + nums[start + 2];

        for (int i = 3; i < dp.size(); ++i) {
            dp[i] = max(
                nums[start + i] + dp[i - 2],
                nums[start + i] + dp[i - 3]);
        }

        return max(dp[dp.size() - 1], dp[dp.size() - 2]);
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
    nums = {2, 7, 9, 3, 1};
    cout << solution.rob(nums) << endl;

    nums = {2, 3, 2};
    cout << solution.rob(nums) << endl;

    nums = {1, 2, 3, 1};
    cout << solution.rob(nums) << endl;
}
