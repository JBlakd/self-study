#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ret(nums.size());
        int even_pointer = 0;
        int odd_pointer = nums.size() - 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                ret[even_pointer] = nums[i];
                ++even_pointer;
            } else {
                ret[odd_pointer] = nums[i];
                --odd_pointer;
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> input;
    vector<int> output;

    input = {3,1,2,4};
    output = solution.sortArrayByParity(input);
    for (int num : output) {
        cout << num << ", ";
    }
    cout << endl;

    input = {0};
    output = solution.sortArrayByParity(input);
    for (int num : output) {
        cout << num << ", ";
    }
    cout << endl;
}
