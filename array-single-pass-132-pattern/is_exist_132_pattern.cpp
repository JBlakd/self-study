#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        int max = -1000000001;
        int max_idx = -1;
        int min = 1000000001;
        int min_idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max) {
                max = nums[i];
                max_idx = i;
            }
            if (nums[i] < min) {
                min = nums[i];
                min_idx = i;
            }

            if (nums[i] < max && nums[i] > min && max_idx < i && max_idx > min_idx) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> input;

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
