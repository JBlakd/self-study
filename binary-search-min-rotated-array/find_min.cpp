#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // at this point lo == hi == index of smallest element
        return nums[lo];
    }
};

int main() {
    Solution solution;
    vector<int> input;

    input = {3,4,5,1,2};
    cout << solution.findMin(input) << endl;

    input = {4,5,6,7,0,1,2};
    cout << solution.findMin(input) << endl;

    input = {11,13,15,17};
    cout << solution.findMin(input) << endl;
}
