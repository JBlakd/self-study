#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur_vec = {};
        int cur_sum = 0;
        vector<vector<int>> ret = {};
        // Start at all indices
        dfs(cur_vec, cur_sum, ret, candidates, 0, target);
        return ret;
    }

   private:
    void dfs(vector<int>& cur_vec, int& cur_sum, vector<vector<int>>& ret, vector<int>& candidates, int cur_index, int target) {
        // found!
        if (cur_sum == target) {
            ret.push_back(cur_vec);
            return;
        }

        // don't continue if sum exceeds target
        if (cur_sum > target) {
            return;
        }

        // At this point, can continue to explore all indices
        while (cur_index < candidates.size()) {
            cur_vec.push_back(candidates[cur_index]);
            cur_sum += candidates[cur_index];
            dfs(cur_vec, cur_sum, ret, candidates, cur_index, target);

            // after return, backtrack
            cur_sum -= candidates[cur_index];
            cur_vec.pop_back();
            ++cur_index;
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
    vector<int> candidates;
    int target;
    vector<vector<int>> output;

    candidates = {2, 3, 5};
    target = 8;
    output = solution.combinationSum(candidates, target);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;

    candidates = {2};
    target = 1;
    output = solution.combinationSum(candidates, target);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;

    candidates = {2, 3, 6, 7};
    target = 7;
    output = solution.combinationSum(candidates, target);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;
}
