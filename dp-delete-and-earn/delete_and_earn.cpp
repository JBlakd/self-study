#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max_in_dp = 0;

        map<int, int> max_cumulated;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                max_cumulated[nums[i - 1]] = dp[i - 1];
                // Iterate backwards through ordered map to find the number with the greatest cumulated point
                // It must beat the current one
                int max_found = 0;
                map<int, int>::iterator it(max_cumulated.find(nums[i - 1]));
                while (true) {
                    if ((*it).first == nums[i] - 1) {
                        if (it == max_cumulated.begin()) {
                            break;
                        } else {
                            --it;
                            continue;
                        }
                    }
                    if ((*it).second > max_found) {
                        max_found = (*it).second;
                    }

                    if (it == max_cumulated.begin()) {
                        break;
                    } else {
                        --it;
                    }
                }
                // Assign nums[i] as the max found + nums[i]
                dp[i] = max_found + nums[i];
            } else {
                dp[i] = nums[i] + dp[i - 1];
            }
            max_in_dp = max(dp[i], max_in_dp);
        }

        return max_in_dp;
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

    nums = {1, 6, 3, 3, 8, 4, 8, 10, 1, 3};
    cout << solution.deleteAndEarn(nums) << endl;

    nums = {2, 2, 3, 3, 3, 4};
    cout << solution.deleteAndEarn(nums) << endl;

    nums = {3, 4, 2};
    cout << solution.deleteAndEarn(nums) << endl;

    nums = {6, 6, 7, 8, 9, 10};
    cout << solution.deleteAndEarn(nums) << endl;

    nums = {6, 6, 8, 8, 9, 10, 11};
    cout << solution.deleteAndEarn(nums) << endl;
}
