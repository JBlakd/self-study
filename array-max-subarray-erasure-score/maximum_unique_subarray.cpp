#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ret = 0;
        int cur_score = 0;
        unordered_set<int> num_set;

        for (int lo = 0, hi = 0; hi < nums.size(); ++hi) {
            if (num_set.find(nums[hi]) == num_set.end()) {
                // unique encountered
                cur_score += nums[hi];
                num_set.emplace(nums[hi]);
            } else {
                // non-unique encountered. Store cur_score.
                ret = max(ret, cur_score);

                // accumulate the move recently encountered
                cur_score += nums[hi];

                // increment lo until lo is at first element after non-unique
                while (nums[lo] != nums[hi]) {
                    // At the same time, erase from the set and subtract from cur_score
                    num_set.erase(nums[lo]);
                    cur_score -= nums[lo];
                    ++lo;
                }

                // now lo is at repeating element
                cur_score -= nums[lo];
                ++lo;
            }
        }

        ret = max(ret, cur_score);
        return ret;
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

    // 22
    nums = {1, 2, 7, 1, 2, 3, 5, 1, 2, 3, 4, 7, 2, 3, 1, 4, 1, 2, 3};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 10
    nums = {1, 2, 3, 4, 2, 4, 3, 2, 1};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 16911
    nums = {187, 470, 25, 436, 538, 809, 441, 167, 477, 110, 275, 133, 666, 345, 411, 459, 490, 266, 987, 965, 429, 166, 809, 340, 467, 318, 125, 165, 809, 610, 31, 585, 970, 306, 42, 189, 169, 743, 78, 810, 70, 382, 367, 490, 787, 670, 476, 278, 775, 673, 299, 19, 893, 817, 971, 458, 409, 886, 434};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 17
    nums = {1, 2, 7, 1, 2, 3, 7, 1, 2, 3, 4, 7};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 6
    nums = {2, 3, 2, 3, 3, 3, 1, 2, 3};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 3
    nums = {1, 2, 1, 2, 1, 2, 1, 2};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 4455
    nums = {4455};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 17
    nums = {4, 2, 4, 5, 6};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 4
    nums = {4, 4, 4, 4, 4, 4};
    cout << solution.maximumUniqueSubarray(nums) << '\n';

    // 8
    nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    cout << solution.maximumUniqueSubarray(nums) << '\n';
}
