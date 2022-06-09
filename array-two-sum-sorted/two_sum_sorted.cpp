#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Sorted input, exactly one solution

        // Two pointers
        vector<int> ret = {0, (int)numbers.size() - 1};
        int& lo = ret[0];
        int& hi = ret[1];

        while (numbers[hi] + numbers[lo] != target) {
            if (numbers[hi] + numbers[lo] > target) {
                --hi;
            } else {
                ++lo;
            }
        }

        ++lo;
        ++hi;
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
    vector<int> numbers;
    int target;

    // 1, 2
    numbers = {2, 7, 11, 15};
    target = 9;
    print_vector(solution.twoSum(numbers, target));
    cout << '\n';

    // 1, 3
    numbers = {2, 3, 4};
    target = 6;
    print_vector(solution.twoSum(numbers, target));
    cout << '\n';

    // 1, 2
    numbers = {-1, 0};
    target = -1;
    print_vector(solution.twoSum(numbers, target));
    cout << '\n';
}
