#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        // <left_rolling_sum, num elements removed from left>
        unordered_map<int, int> hashmap;
        hashmap[0] = 0;
        int sum = 0;
        // Populate the hashmap from the left
        for (int i = 1; i <= nums.size(); ++i) {
            sum += nums[i - 1];
            if (sum <= x) {
                hashmap[sum] = i;
            }
        }

        if (sum < x) {
            return -1;
        }

        // Find complement from the right
        int complement = x;
        // Check for the case where we don't need to remove anything from the right
        int ret = numeric_limits<int>::max();
        if (hashmap.find(complement) != hashmap.end()) {
            ret = hashmap.at(complement);
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            complement -= nums[i];
            if (hashmap.find(complement) != hashmap.end()) {
                // number of elements removed from the right == nums.size() - i
                int cur_elements_removed = (nums.size() - i) + hashmap.at(complement);
                ret = min(ret, cur_elements_removed);
            }
        }
        return (ret == numeric_limits<int>::max()) ? -1 : ret;
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
    int x;

    // -1
    nums = {1, 1};
    x = 3;
    cout << solution.minOperations(nums, x) << '\n';

    // 1
    nums = {1, 1, 3, 2, 5};
    x = 5;
    cout << solution.minOperations(nums, x) << '\n';

    // 2
    nums = {1, 1, 4, 2, 3};
    x = 5;
    cout << solution.minOperations(nums, x) << '\n';

    // 2
    nums = {1, 3, 4, 1};
    x = 4;
    cout << solution.minOperations(nums, x) << '\n';

    // 5
    nums = {3, 2, 20, 1, 1, 3};
    x = 10;
    cout << solution.minOperations(nums, x) << '\n';

    // 4
    nums = {1, 3, 4, 1};
    x = 9;
    cout << solution.minOperations(nums, x) << '\n';

    // 16
    nums = {8828, 9581, 49, 9818, 9974, 9869, 9991, 10000, 10000, 10000, 9999, 9993, 9904, 8819, 1231, 6309};
    x = 134365;
    cout << solution.minOperations(nums, x) << '\n';

    // 113
    nums = {5207, 5594, 477, 6938, 8010, 7606, 2356, 6349, 3970, 751, 5997, 6114, 9903, 3859, 6900, 7722, 2378, 1996, 8902, 228, 4461, 90, 7321, 7893, 4879, 9987, 1146, 8177, 1073, 7254, 5088, 402, 4266, 6443, 3084, 1403, 5357, 2565, 3470, 3639, 9468, 8932, 3119, 5839, 8008, 2712, 2735, 825, 4236, 3703, 2711, 530, 9630, 1521, 2174, 5027, 4833, 3483, 445, 8300, 3194, 8784, 279, 3097, 1491, 9864, 4992, 6164, 2043, 5364, 9192, 9649, 9944, 7230, 7224, 585, 3722, 5628, 4833, 8379, 3967, 5649, 2554, 5828, 4331, 3547, 7847, 5433, 3394, 4968, 9983, 3540, 9224, 6216, 9665, 8070, 31, 3555, 4198, 2626, 9553, 9724, 4503, 1951, 9980, 3975, 6025, 8928, 2952, 911, 3674, 6620, 3745, 6548, 4985, 5206, 5777, 1908, 6029, 2322, 2626, 2188, 5639};
    x = 565610;
    cout << solution.minOperations(nums, x) << '\n';

    // 6
    nums = {6016, 5483, 541, 4325, 8149, 3515, 7865, 2209, 9623, 9763, 4052, 6540, 2123, 2074, 765, 7520, 4941, 5290, 5868, 6150, 6006, 6077, 2856, 7826, 9119};
    x = 31841;
    cout << solution.minOperations(nums, x) << '\n';

    // -1
    nums = {5, 6, 7, 8, 9};
    x = 4;
    cout << solution.minOperations(nums, x) << '\n';
}
