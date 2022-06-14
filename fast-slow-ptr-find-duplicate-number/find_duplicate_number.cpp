#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // first phase, advance until slow and fast are the same
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Just in case we end up at the target after first phase
        if (nums[slow] == nums[0]) {
            return nums[slow];
        }

        // move slow back to beginning
        slow = 0;

        // second phase, advance both pointers at the same pace
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (nums[slow] != nums[fast]);

        // both pointers are at the cycle start.
        return nums[slow];
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
    int output;

    nums = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    output = solution.findDuplicate(nums);
    cout << output << '\n';
    assert((output == 9));

    nums = {3, 1, 3, 4, 2};
    output = solution.findDuplicate(nums);
    cout << output << '\n';
    assert((output == 3));

    nums = {1, 3, 4, 2, 2};
    output = solution.findDuplicate(nums);
    cout << output << '\n';
    assert((output == 2));

    cout << "Great success!" << '\n';
}
