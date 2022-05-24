#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int local_max = -10001;
        int global_max = -10001;
        for (int i = 0; i < nums.size(); ++i) {
            local_max = max(nums[i], nums[i] + local_max);
            global_max = max(global_max, local_max);
        }

        return global_max;
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
