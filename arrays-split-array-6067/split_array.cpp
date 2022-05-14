#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int waysToSplitArray(vector<int>& nums) {
        int ret = 0;
        long long first_half = 0;
        long long second_half = 0;
        // calculate second half
        for (int i = 0; i < nums.size(); ++i) {
            second_half += (long long)nums[i];
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            first_half += (long long)nums[i];
            second_half -= (long long)nums[i];

            // cout << "first_half: " << first_half << " second_half: " << second_half;

            if (first_half >= second_half) {
                // cout << " found!";
                ++ret;
            }

            // cout << endl;
        }

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

    nums = {-100000, -2147400000};
    cout << solution.waysToSplitArray(nums) << endl;

    nums = {-2147400000, -100000};
    cout << solution.waysToSplitArray(nums) << endl;

    nums = {-1, 2};
    cout << solution.waysToSplitArray(nums) << endl;

    nums = {2, -1};
    cout << solution.waysToSplitArray(nums) << endl;

    nums = {2, 3, 1, 0};
    cout << solution.waysToSplitArray(nums) << endl;

    nums = {10, 4, -8, 7};
    cout << solution.waysToSplitArray(nums) << endl;
}
