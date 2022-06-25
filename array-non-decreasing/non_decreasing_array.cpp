#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 2) {
            return true;
        }

        int num_decreases = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                ++num_decreases;
                if (num_decreases == 2) {
                    return false;
                }

                // check i - 1
                if (i - 1 == 0 || (i - 1 > 0 && nums[i] >= nums[i - 2])) {
                    // i - 1 passed
                    continue;
                }

                // i - 1 didn't pass, now check i
                if (i == nums.size() - 1 || (i < nums.size() - 1 && nums[i + 1] >= nums[i - 1])) {
                    // i passed
                    continue;
                }

                return false;
            }
        }

        return true;
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
    bool output;

    nums = {1, 2, 3, 4, 2, 3};
    output = solution.checkPossibility(nums);
    cout << ((output) ? "true\n" : "false\n");
    assert(output == false);

    nums = {1, 2, 3, 4, 2, 6};
    output = solution.checkPossibility(nums);
    cout << ((output) ? "true\n" : "false\n");
    assert(output == true);

    nums = {1, 2, 2, 4, 2, 3};
    output = solution.checkPossibility(nums);
    cout << ((output) ? "true\n" : "false\n");
    assert(output == true);

    nums = {4, 2, 3};
    output = solution.checkPossibility(nums);
    cout << ((output) ? "true\n" : "false\n");
    assert(output == true);

    nums = {4, 2, 1};
    output = solution.checkPossibility(nums);
    cout << ((output) ? "true\n" : "false\n");
    assert(output == false);

    cout << "Great success!" << '\n';
}
