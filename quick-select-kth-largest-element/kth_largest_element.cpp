#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums.size() - 1, 0, nums, k);
    }

   private:
    int quickselect(int hi, int lo, vector<int>& nums, int k) {
        if (hi == lo) {
            return nums[hi];
        }
        // select random pivot and move it to the end
        int rand_idx = lo + rand() % (hi - lo + 1);
        swap(rand_idx, hi, nums);

        int end_of_smaller = -1;
        int end_of_bigger = 0;
        // End of bigger stops before the pivot
        while (end_of_bigger < hi) {
            if (nums[end_of_bigger] <= nums[hi]) {
                ++end_of_smaller;
                swap(end_of_smaller, end_of_bigger, nums);
            }
            ++end_of_bigger;
        }
        swap(hi, end_of_smaller + 1, nums);

        // partitioning done. The pivot is now at index (end_of_smaller + 1).
        // The element at index (nums.size() - k) contains the kth largest element
        if (end_of_smaller + 1 < nums.size() - k) {
            // pivot is left of the kth largest element
            return quickselect(hi, end_of_smaller + 2, nums, k);
        } else if (end_of_smaller + 1 > nums.size() - k) {
            // pivot is right of the kth largest element
            return quickselect(end_of_smaller, lo, nums, k);
        } else {
            // return pivot as pivot is the kth largest element
            return nums[end_of_smaller + 1];
        }
    }

    void swap(int idx1, int idx2, vector<int>& nums) {
        if (idx1 == idx2) {
            return;
        }
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
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
    int k;

    nums = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    k = 1;
    cout << solution.findKthLargest(nums, k) << endl;

    nums = {99, 99};
    k = 1;
    cout << solution.findKthLargest(nums, k) << endl;

    // 5
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    cout << solution.findKthLargest(nums, k) << endl;

    // 7
    nums = {3, 8, 1, 7, 2, 6, 9, 4};
    k = 3;
    cout << solution.findKthLargest(nums, k) << endl;

    // 4
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    k = 4;
    cout << solution.findKthLargest(nums, k) << endl;
}
