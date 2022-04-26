#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        // find index of smallest element
        // u wot m8 how am I meant to come up with this myself, just rote learn this part
        // I guess I can derive it in real time by writing down the array on paper
        // and then try to compare what I result with my memory as best I can
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) {
                // mid still lies on the bigger section of the array
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        // Now, lo == high == index of smallest element
        int pivot_index = lo;
        // Determine if the array is even rotated
        if (pivot_index == 0) {
            // not rotated. binary search as normal
            lo = 0;
            hi = nums.size() - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            // Return unsuccessful
            return -1;
        } else {
            // rotated
            // Determine which rotated array section to search in
            hi = nums.size() - 1;
            if (target >= nums[pivot_index] && target <= nums[hi]) {
                // The target is in the same array section as the pivot index
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (nums[mid] == target) {
                        return mid;
                    } else if (nums[mid] < target) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                // Return unsuccessful
                return -1;
            } else {
                // The target is in the other array section as the pivot index
                hi = pivot_index - 1;
                lo = 0;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (nums[mid] == target) {
                        return mid;
                    } else if (nums[mid] < target) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                // Return unsuccessful
                return -1;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> input;
    int target;

    input = {4,5,6,7,0,1,2};
    target = 0;
    cout << solution.search(input, target) << endl;

    input = {4,5,6,7,0,1,2};
    target = 3;
    cout << solution.search(input, target) << endl;

    input = {1};
    target = 0;
    cout << solution.search(input, target) << endl;
}
