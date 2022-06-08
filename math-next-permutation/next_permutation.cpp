#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }

        // find first non-increasing element, counting backwards
        int pivot = nums.size() - 2;
        while (pivot > -1) {
            if (nums[pivot] < nums[pivot + 1]) {
                break;
            }
            --pivot;
        }
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Swap the first non-increasing element with the smallest number in the tail range that is bigger than the first non-increasing element
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Reverse the tail range (non-inclusive of the first non-increasing element)
        reverse(nums.begin() + pivot + 1, nums.end());
        return;
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
}
