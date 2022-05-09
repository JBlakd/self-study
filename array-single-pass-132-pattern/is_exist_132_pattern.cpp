#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        // As soon as increase is detected, keep track of
        // - beginning of increase
        // - current maximum
        // - first value which violates monotonic increase. Check this value for 132 condition

        bool increasing = nums[1] > nums[0];
        int local_min = nums[0];
        int local_max = nums[1];
        for (int i = 2; i < nums.size(); ++i) {
            if (increasing) {
                if (nums[i] > local_min && nums[i] < local_max) {
                    return true;
                } else if (nums[i] < local_min && nums[i] < local_max) {
                    increasing = false;
                    local_min = nums[i];
                }
                // else increasing remains true (untouched)
            } else {
                // if not already increasing, the we can't return anything. 
                // Most we can do is to change the increasing boolean to true, and to change the local_min or max variables
                if (nums[i] > nums[i - 1]) {
                    increasing = true;
                    local_min = nums[i - 1];
                    local_max = nums[i];
                }
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> input;

    // true
    input = {3, 1, 4, 2};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // false (this testcase defeats monotonic increase/decrease approach)
    input = {3, 6, 3};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // true
    input = {3, 5, 0, 3, 4};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // false
    input = {1, 2, 3, 4};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // true
    input = {-1, 3, 2, 0};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;
}
