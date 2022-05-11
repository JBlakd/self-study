#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int last_set_index = 0;
        // set nums.size() number of least significant bits to 1
        // for example, if nums.size() == 3, set last_set_index to 0b111
        for (int i = 0; i < nums.size(); ++i) {
            last_set_index |= (1 << i);
        }

        vector<vector<int>> ret;
        // This loop will populate the ret;
        for (int i = 0; i <= last_set_index; ++i) {
            vector<int> cur_set;
            // Loop through the bits
            for (int j = 0; j < nums.size(); ++j) {
                // if the current bit is set
                if ((1 << j) & i) {
                    cur_set.push_back(nums[nums.size() - 1 - j]);
                }
            }
            ret.push_back(cur_set);
        }

        return ret;
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
    vector<vector<int>> output;

    nums = {1, 2, 3};
    output = solution.subsets(nums);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;
}
