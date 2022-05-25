#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }

        // this vector is not identical to the longest increasing subsequence
        vector<int> subsequence(1, nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > subsequence.back()) {
                subsequence.push_back(nums[i]);
            } else {
                auto it = lower_bound(subsequence.begin(), subsequence.end(), nums[i]);
                *it = nums[i];
            }
        }

        return subsequence.size();
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

    // 3
    nums = {4, 10, 4, 3, 8, 9};
    cout << solution.lengthOfLIS(nums) << '\n';

    // 4
    nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solution.lengthOfLIS(nums) << '\n';

    // 4
    nums = {0, 1, 0, 3, 2, 3};
    cout << solution.lengthOfLIS(nums) << '\n';

    // 1
    nums = {7, 7, 7, 7, 7, 7, 7};
    cout << solution.lengthOfLIS(nums) << '\n';
}
