// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPossible(vector<int>& target) {
        // it ain't this simple, see {5,8} testcase
        sort(target.begin(), target.end());

        vector<int> cur_vec(target.size(), 1);
        int cur_sum = target.size();
        for (int i = 0; i < target.size(); ++i) {
            while (cur_vec[i] < target[i]) {
                int change = cur_sum - cur_vec[i];
                cur_vec[i] += change;
                cur_sum += change;
            }
            if (cur_vec[i] > target[i]) {
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
    vector<int> target;

    target = {8, 5};
    assert(solution.isPossible(target) == true);

    target = {9, 3, 5};
    assert(solution.isPossible(target) == true);

    target = {1, 1, 1, 2};
    assert(solution.isPossible(target) == false);

    target = {4, 7, 10};
    assert(solution.isPossible(target) == false);

    target = {5, 7, 10};
    assert(solution.isPossible(target) == false);

    cout << "Great success!" << '\n';
}
