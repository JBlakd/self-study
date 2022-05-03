#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }

        // Scan forward for first non-monotonously increasing element and index
        int forward_index = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                forward_index = i;
                break;
            }
        }

        // Scan backward for first non-monotonously decreasing element and index
        int backward_index = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                backward_index = i;
                break;
            }
        }

        // Return the case where the array is already perfectly sorted
        if (forward_index == -1 || backward_index == -1) {
            return 0;
        }

        // From forward_index till the end of the array, find the minimum value
        int min_unsorted = 100001;
        for (int i = forward_index; i < nums.size(); ++i) {
            if (nums[i] < min_unsorted) {
                min_unsorted = nums[i];
            }
        }

        // From backward_index till the beginning of the array, find the max value
        int max_unsorted = -100001;
        for (int i = backward_index; i >= 0; --i) {
            if (nums[i] > max_unsorted) {
                max_unsorted = nums[i];
            }
        }

        // Scan forward to determine the index where the first forward-scan erroneous value should be
        int forward_index_corrected = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > min_unsorted) {
                forward_index_corrected = i;
                break;
            }
        }

        // Scan backward to determine the index where the first backward-scan erroneous value should be
        int backward_index_corrected = -1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < max_unsorted) {
                backward_index_corrected = i;
                break;
            }
        }

        return backward_index_corrected - forward_index_corrected + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums;

    // 4
    nums = {1, 3, 5, 4, 2};
    cout << solution.findUnsortedSubarray(nums) << endl;

    // 3
    nums = {1, 2, 4, 5, 3};
    cout << solution.findUnsortedSubarray(nums) << endl;

    // 2    b  f
    nums = {2, 1};
    cout << solution.findUnsortedSubarray(nums) << endl;

    // 4
    nums = {1, 3, 2, 2, 2};
    cout << solution.findUnsortedSubarray(nums) << endl;

    // 0
    nums = {2};
    cout << solution.findUnsortedSubarray(nums) << endl;

    // 0    b  f
    nums = {1, 2};
    cout << solution.findUnsortedSubarray(nums) << endl;

    // 0    b        f
    nums = {1, 2, 3, 4};
    cout << solution.findUnsortedSubarray(nums) << endl;

    // 2       b  f
    nums = {2, 6, 4, 8, 9, 10, 15};
    cout << solution.findUnsortedSubarray(nums) << endl;

    // 5          f     b
    nums = {2, 6, 4, 8, 10, 9, 15};
    cout << solution.findUnsortedSubarray(nums) << endl;
}
