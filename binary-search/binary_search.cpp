#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> input;
    int target;

    input = {5};
    target = 5;
    cout << solution.search(input, target) << endl;

    input = {-1, 0, 3, 5, 9, 12};
    target = 2;
    cout << solution.search(input, target) << endl;

    input = {-1, 0, 3, 5, 9, 12};
    target = 9;
    cout << solution.search(input, target) << endl;
}
