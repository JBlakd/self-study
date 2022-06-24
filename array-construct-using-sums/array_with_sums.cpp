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
        // Subtract the largest with the rest of the array, and put the new element into the array. Repeat until all elements become one
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
