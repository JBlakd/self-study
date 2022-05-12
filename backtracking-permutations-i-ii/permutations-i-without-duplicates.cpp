#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<vector<int>> ret;
        vector<int> cur_vec;
        dfs(0, cur_vec, nums, ret, used);
        return ret;
    }

   private:
    void dfs(int cur_idx, vector<int>& cur_vec, vector<int>& nums, vector<vector<int>>& ret, vector<bool>& used) {
        // cout << "cur_idx: " << cur_idx << ". Exploring: ";
        // print_vector(cur_vec);

        if (cur_vec.size() == nums.size()) {
            ret.push_back(cur_vec);
            // cout << " (found!)" << endl;
            return;
        }
        // cout << endl;

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            cur_vec.push_back(nums[i]);
            used[i] = true;
            dfs(i, cur_vec, nums, ret, used);
            // backtrack
            used[i] = false;
            cur_vec.pop_back();
        }
    }

    // template <typename T>
    // void print_vector(vector<T> vec) {
    //     cout << "{";
    //     for (int i = 0; i < vec.size(); i++) {
    //         cout << vec[i];
    //         if (i != vec.size() - 1) {
    //             cout << ", ";
    //         }
    //     }
    //     cout << "}";
    // }
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

    nums = {};
    output = solution.permute(nums);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;

    nums = {1};
    output = solution.permute(nums);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;

    nums = {1, 2, 3};
    output = solution.permute(nums);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;

    // nums = {1, 1, 2};
    // output = solution.permuteUnique(nums);
    // for (auto vec : output) {
    //     print_vector(vec);
    //     cout << ", ";
    // }
    // cout << endl;

    // nums = {1, 2, 2, 4};
    // output = solution.permuteUnique(nums);
    // for (auto vec : output) {
    //     print_vector(vec);
    //     cout << ", ";
    // }
    // cout << endl;
}
