#include <cassert>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        // maintain pq of <value, idx>
        priority_queue<pair<int, int>> pq;
        int cur_dp = numeric_limits<int>::min();

        for (int i = 0; i < nums.size(); ++i) {
            if (!pq.empty()) {
                while (pq.top().second < i - k) {
                    pq.pop();
                }
                cur_dp = nums[i] + pq.top().first;
            } else {
                cur_dp = nums[i];
            }

            pq.emplace(cur_dp, i);
        }

        return cur_dp;
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
    int k;
    int output;

    nums = {8};
    k = 2;
    output = solution.maxResult(nums, k);
    cout << output << '\n';
    assert(output == 8);

    nums = {0};
    k = 2;
    output = solution.maxResult(nums, k);
    cout << output << '\n';
    assert(output == 0);

    nums = {-1};
    k = 2;
    output = solution.maxResult(nums, k);
    cout << output << '\n';
    assert(output == -1);

    nums = {1, -1, -2, 4, -7, 3};
    k = 2;
    output = solution.maxResult(nums, k);
    cout << output << '\n';
    assert(output == 7);

    nums = {10, -5, -2, 4, 0, 3};
    k = 3;
    output = solution.maxResult(nums, k);
    cout << output << '\n';
    assert(output == 17);

    nums = {1, -5, -20, 4, -1, 3, -6, -3};
    k = 2;
    output = solution.maxResult(nums, k);
    cout << output << '\n';
    assert(output == 0);

    cout << "Great success!" << '\n';
}
