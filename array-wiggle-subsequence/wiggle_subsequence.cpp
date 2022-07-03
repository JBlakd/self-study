#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }

        // find first index containing number different to nums[0]
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[0]) {
                i = j;
                break;
            }
        }

        // all numbers in nums the same
        if (i == 0) {
            return 1;
        }

        // the first index is opposite to what's expected
        bool is_up = (nums[i] < nums[0]);
        int ret = 1;
        for (; i < nums.size(); ++i) {
            if ((is_up && nums[i] < nums[i - 1]) || (!is_up && nums[i] > nums[i - 1])) {
                ++ret;
                is_up = nums[i] > nums[i - 1];
            }
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
    int output;

    nums = {16};
    output = solution.wiggleMaxLength(nums);
    cout << output << '\n';
    assert(output == 1);

    nums = {2, 1};
    output = solution.wiggleMaxLength(nums);
    cout << output << '\n';
    assert(output == 2);

    nums = {2, 2};
    output = solution.wiggleMaxLength(nums);
    cout << output << '\n';
    assert(output == 1);

    nums = {1, 17, 5, 10, 13, 15, 14, 5, 16, 8};
    output = solution.wiggleMaxLength(nums);
    cout << output << '\n';
    assert(output == 7);

    nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    output = solution.wiggleMaxLength(nums);
    cout << output << '\n';
    assert(output == 7);

    nums = {1, 7, 4, 9, 2, 5};
    output = solution.wiggleMaxLength(nums);
    cout << output << '\n';
    assert(output == 6);

    nums = {6, 7, 7, 5, 4, 8, 9, 10};
    output = solution.wiggleMaxLength(nums);
    cout << output << '\n';
    assert(output == 4);

    nums = {2, 2, 5, 4, 9, 7, 6};
    output = solution.wiggleMaxLength(nums);
    cout << output << '\n';
    assert(output == 5);

    cout << "Great success!" << '\n';
}
