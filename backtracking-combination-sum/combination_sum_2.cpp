#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort the array. Key difference compared to Comb Sum I
        sort(candidates.begin(), candidates.end());
        vector<int> cur_vec = {};
        int cur_sum = 0;
        unordered_set<vector<int>> ret_set;

        // Start at all indices
        for (int cur_index = 0; cur_index < candidates.size(); ++cur_index) {
            // Avoid duplicates. Key difference compared to Comb Sum I
            if (cur_index >= 1 && candidates[cur_index] == candidates[cur_index - 1]) {
                continue;
            }
            dfs(cur_vec, cur_sum, ret_set, candidates, cur_index, target);
        }

        vector<vector<int>> ret(ret_set.begin(), ret_set.end());
        return ret;
    }

   private:
    void dfs(vector<int>& cur_vec, int& cur_sum, unordered_set<vector<int>>& ret_set, vector<int>& candidates, int cur_index, int target) {
        cur_vec.push_back(candidates[cur_index]);
        cur_sum += candidates[cur_index];

        // cout << "Exploring ";
        // print_vector(cur_vec);
        // cout << " Sum: " << cur_sum << " ";

        if (cur_sum >= target) {
            if (cur_sum == target) {
                // cout << " (worked)";
                if (ret_set.find(cur_vec) == ret_set.end()) {
                    ret_set.insert(cur_vec);
                }
            }

            // backtrack
            cur_sum -= candidates[cur_index];
            cur_vec.pop_back();
            // cout << endl;
            return;
        } else {
            // haven't reached sum yet. Try all subsequent indices
            // + 1 so we don't look into the same number. Key difference from Combination Sum I
            for (int i = cur_index + 1; i < candidates.size(); ++i) {
                dfs(cur_vec, cur_sum, ret_set, candidates, i, target);
            }
            // tried all options. time to backtrack
            cur_sum -= candidates[cur_index];
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
    vector<int> candidates;
    int target;
    vector<vector<int>> output;

    candidates = {2, 5, 2, 1, 2, 2};
    target = 7;
    output = solution.combinationSum(candidates, target);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;
}
