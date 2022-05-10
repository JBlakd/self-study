#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur_vec = {};
        int cur_sum = 0;
        vector<vector<int>> ret = {};
        // Start at all indices
        dfs(cur_vec, cur_sum, ret, candidates, 0, target);
        return ret;
    }

   private:
    void dfs(vector<int>& cur_vec, int& cur_sum, vector<vector<int>>& ret, vector<int>& candidates, int cur_index, int target) {
        // cout << "Explored: ";
        // print_vector(cur_vec);

        // found!
        if (cur_sum == target) {
            ret.push_back(cur_vec);
            // cout << " found!";
            // cout << endl;
            return;
        }

        // don't continue if sum exceeds target
        if (cur_sum > target) {
            // cout << endl;
            return;
        }

        // cout << endl;

        // At this point, can continue to explore all indices
        while (cur_index < candidates.size()) {
            cur_vec.push_back(candidates[cur_index]);
            cur_sum += candidates[cur_index];
            // Don't explore the same element for the next recursion, explore the next one instead
            dfs(cur_vec, cur_sum, ret, candidates, cur_index + 1, target);

            // after return, backtrack
            cur_sum -= candidates[cur_index];
            cur_vec.pop_back();
            int just_explored = candidates[cur_index];
            // during backtracking, only explore the next index containing a different element
            while (cur_index < candidates.size() && candidates[cur_index] == just_explored) {
                ++cur_index;
            }
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

    // {}
    candidates = {2};
    target = 1;
    output = solution.combinationSum2(candidates, target);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;

    // {1,1,6}, {1,2,5}, {1,7}, {2,6}
    candidates = {10, 1, 2, 7, 6, 1, 5};
    target = 8;
    output = solution.combinationSum2(candidates, target);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;

    // {1,2,2}, {5}
    candidates = {2, 5, 2, 1, 2};
    target = 5;
    output = solution.combinationSum2(candidates, target);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;
}
