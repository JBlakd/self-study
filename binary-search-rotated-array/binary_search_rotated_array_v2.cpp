#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        // binary search to find the smallest element
        // i.e. the element whose left neighbour is bigger than it
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // now lo is the index of the smallest element
        // Determine which half of the sorted rotated array to perform binary search on
        if (target >= nums[lo] && target <= nums.back()) {
            auto it = lower_bound(nums.begin() + lo, nums.end(), target);
            return (*(it) == target) ? it - nums.begin() : -1;
        } else {
            auto it = lower_bound(nums.begin(), nums.begin() + lo - 1, target);
            return (*(it) == target) ? it - nums.begin() : -1;
        }
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

    // 4
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    cout << solution.search(nums, target) << '\n';
}
