#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // The product of array except self is the product of the non-inclusive prefix and suffix products

        // Calculate prefix first
        vector<int> ret(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            ret[i] = ret[i - 1] * nums[i - 1];
        }

        // Calcualate suffix in-place and put it in ret to achieve O(1) space complexity
        int prev_suffix = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            int cur_suffix = prev_suffix * nums[i + 1];
            ret[i] *= cur_suffix;
            prev_suffix = cur_suffix;
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

    nums = {1, 2, 3, 4};
    print_vector(solution.productExceptSelf(nums));
    cout << '\n';

    nums = {-1, 1, 0, -3, 3};
    print_vector(solution.productExceptSelf(nums));
    cout << '\n';
}
