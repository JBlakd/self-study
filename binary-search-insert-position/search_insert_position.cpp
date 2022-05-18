#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        // Search for the index containing the number equal to target, if it exists
        // or search for the index containing the first number bigger than the target
        int top = nums.size() - 1;
        int bottom = 0;
        int mid = 0;
        while (top >= bottom) {
            mid = (top + bottom) / 2;
            if (nums[mid] < target) {
                // searched too low
                if (mid == nums.size() - 1 || nums[mid + 1] >= target) {
                    return mid + 1;
                }
                bottom = mid + 1;
            } else if (nums[mid] > target) {
                // searched too high
                if (mid == 0 || nums[mid - 1] < target) {
                    return mid;
                }
                top = mid - 1;
            } else {
                return mid;
            }
        }

        return mid;
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
    int target;

    nums = {1, 3, 5, 6};
    target = 5;
    cout << solution.searchInsert(nums, target) << endl;

    nums = {1, 3, 5, 6};
    target = 2;
    cout << solution.searchInsert(nums, target) << endl;

    nums = {1, 3, 5, 6};
    target = 7;
    cout << solution.searchInsert(nums, target) << endl;
}
