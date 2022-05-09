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

        bool monotonic_increase = nums[1] > nums[0];

        for (int i = 2; i < nums.size(); ++i) {
            // return true as soon as monotonic increasing or monotonic decreasing is violated
            if (monotonic_increase) {
                if (nums[i] < nums[i - 1]) {
                    return true;
                }
            } else {
                if (nums[i] > nums[i - 1]) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> input;

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
    input = {3, 1, 4, 2};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // true
    input = {-1, 3, 2, 0};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;
}
