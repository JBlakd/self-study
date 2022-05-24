#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        cout << "sum: " << accumulate(nums.begin(), nums.end(), 0) << '\n';
        return max(find_max_subarray(nums), accumulate(nums.begin(), nums.end(), 0) - find_min_subarray(nums));
    }

   private:
    int find_max_subarray(vector<int>& nums) {
        int local_max = -10001;
        int global_max = -10001;
        for (int i = 0; i < nums.size(); ++i) {
            local_max = max(nums[i], nums[i] + local_max);
            global_max = max(global_max, local_max);
        }

        cout << "max: " << global_max << '\n';
        return global_max;
    }

    int find_min_subarray(vector<int>& nums) {
        int local_min = 10001;
        int global_min = 10001;
        // Must not include first and last elements due to wraparound issue
        for (int i = 1; i < nums.size() - 1; ++i) {
            local_min = min(nums[i], nums[i] + local_min);
            global_min = min(global_min, local_min);
        }
        cout << "min: " << global_min << '\n';
        return global_min;
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

    nums = {5, -2, 5};
    cout << solution.maxSubarraySumCircular(nums) << '\n';

    nums = {-3, -2, -3};
    cout << solution.maxSubarraySumCircular(nums) << '\n';
}
