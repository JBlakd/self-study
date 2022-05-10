#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> cur_vec = {};
        dfs(ret, cur_vec, 0, k, n);
        return ret;
    }

   private:
    void dfs(vector<vector<int>>& ret, vector<int>& cur_vec, int cur_num, int k, int n) {
        // cout << "Exploring: ";
        // print_vector(cur_vec);
        // cout << " n: " << n << endl;

        // fail base case: no more sum or gone too deep
        if (n < 0 || cur_vec.size() > k) {
            return;
        }

        // success base case
        if (cur_vec.size() == k && n == 0) {
            ret.push_back(cur_vec);
            return;
        }

        // Explore available numbers
        for (int i = cur_num + 1; i <= 9; ++i) {
            if (n - i < 0) {
                continue;
            }
            cur_vec.push_back(i);
            dfs(ret, cur_vec, i, k, n - i);

            // backtrack
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
    int k;
    int n;
    vector<vector<int>> output;

    k = 3;
    n = 9;
    output = solution.combinationSum3(k, n);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;

    k = 3;
    n = 7;
    output = solution.combinationSum3(k, n);
    for (auto vec : output) {
        print_vector(vec);
        cout << ", ";
    }
    cout << endl;
}
