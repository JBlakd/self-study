#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size());

        int furthest_reachable_idx = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (i > furthest_reachable_idx) {
                return false;
            }
            dp[i] = i + nums[i];
            furthest_reachable_idx = max(dp[i], furthest_reachable_idx);
            if (furthest_reachable_idx >= nums.size() - 1) {
                return true;
            }
        }

        return (furthest_reachable_idx >= nums.size() - 1);
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

    // true
    nums = {2, 3, 1, 2, 0, 2, 1, 4};
    cout << (solution.canJump(nums) ? "true" : "false") << endl;

    // true
    nums = {2, 3, 1, 1, 4};
    cout << (solution.canJump(nums) ? "true" : "false") << endl;

    // false
    nums = {3, 2, 1, 0, 4};
    cout << (solution.canJump(nums) ? "true" : "false") << endl;
}
