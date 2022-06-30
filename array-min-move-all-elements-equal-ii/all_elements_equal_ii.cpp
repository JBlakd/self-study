#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minMoves2(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        // quickselect for linear time discovery of median
        int over_two;
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        over_two = nums[nums.size() / 2];
        int over_two_minus_one;
        nth_element(nums.begin(), nums.begin() + nums.size() / 2 - 1, nums.end());
        over_two_minus_one = nums[nums.size() / 2 - 1];

        int ret_over_two = 0;
        int ret_over_two_minus_one = 0;
        for (int& num : nums) {
            ret_over_two += abs(num - over_two);
            ret_over_two_minus_one += abs(num - over_two_minus_one);
        }

        return min(ret_over_two, ret_over_two_minus_one);
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
    int output;

    nums = {3, 24, 4, 4, 6, 3, 2, 3, 6, 6, 34, 67, 3457, 45};
    output = solution.minMoves2(nums);
    cout << output << '\n';
    assert(output == 3614);

    nums = {1, 10, 2, 9};
    output = solution.minMoves2(nums);
    cout << output << '\n';
    assert(output == 16);

    nums = {3};
    output = solution.minMoves2(nums);
    cout << output << '\n';
    assert(output == 0);

    nums = {1, 2, 3};
    output = solution.minMoves2(nums);
    cout << output << '\n';
    assert(output == 2);

    cout << "Great success!" << '\n';
}
