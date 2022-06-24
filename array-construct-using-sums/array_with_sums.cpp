// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPossible(vector<int>& target) {
        /* Subtract the largest with the rest of the array, and put the new element into the array. Repeat until all elements become one */
        if (target.size() == 1) {
            return (target[0] == 1);
        }

        priority_queue<int> q;
        uint64_t cur_sum = 0;
        for (int& num : target) {
            q.emplace(num);
            cur_sum += num;
        }

        while (cur_sum > target.size()) {
            int cur_largest = q.top();
            q.pop();
            cur_sum -= cur_largest;

            // instead of subtracting cur_sum once from cur_largest
            // subtract as much as you can so that afterwards, cur_largest isn't the largest
            int difference = cur_largest - q.top();
            int quotient = difference / cur_sum;
            if (difference % cur_sum == 0 && quotient > 0) {
                cur_largest -= (quotient * cur_sum);
            } else {
                cur_largest -= ((quotient + 1) * cur_sum);
            }

            if (cur_largest < 1) {
                return false;
            }
            q.emplace(cur_largest);
            cur_sum += cur_largest;
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

    target = {9, 9, 9};
    assert(solution.isPossible(target) == false);

    target = {1, 1000000000};
    assert(solution.isPossible(target) == true);

    target = {9, 3, 5};
    assert(solution.isPossible(target) == true);

    target = {8, 5};
    assert(solution.isPossible(target) == true);

    target = {1, 1, 1, 2};
    assert(solution.isPossible(target) == false);

    target = {4, 7, 10};
    assert(solution.isPossible(target) == false);

    target = {5, 7, 10};
    assert(solution.isPossible(target) == false);

    cout << "Great success!" << '\n';
}
