#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Find the number of arr1 elements whose absolute value distance with every arr2 element is strictly greater than d
        // Just sort arr2, and find the closest element to the arr1 element.
        // If the closest element has a distance less than or equal to d, then this arr1 element doesn't count

        int ret = 0;

        sort(arr2.begin(), arr2.end());

        for (auto& element : arr1) {
            auto arr2_it = lower_bound(arr2.begin(), arr2.end(), element);
            int closest = *(arr2_it);
            // Find the true closest
            if (arr2_it != arr2.begin() && element - *(arr2_it - 1) < closest - element) {
                closest = *(arr2_it - 1);
            } else if (arr2_it == arr2.end()) {
                // if lower_bound not found, then last element is the closest
                closest = *(arr2.end() - 1);
            }

            // See if closest has distance less than or equal to d
            if (abs(element - closest) > d) {
                ++ret;
            }
        }

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
    vector<int> arr1;
    vector<int> arr2;
    int d;

    // 0
    arr1 = {-3, 2, -5, 7, 1};
    arr2 = {4};
    d = 84;
    cout << solution.findTheDistanceValue(arr1, arr2, d) << endl;

    // 2
    arr1 = {100, 200};
    arr2 = {4, 10, -4, 5, 2};
    d = 55;
    cout << solution.findTheDistanceValue(arr1, arr2, d) << endl;

    // 2
    arr1 = {-100, -200};
    arr2 = {4, 10, -4, 5, 2};
    d = 55;
    cout << solution.findTheDistanceValue(arr1, arr2, d) << endl;

    // 0
    arr1 = {-8, -7};
    arr2 = {4, 10, -4, 5, 2};
    d = 55;
    cout << solution.findTheDistanceValue(arr1, arr2, d) << endl;

    // 2
    arr1 = {4, 5, 8};
    arr2 = {10, 9, 1, 8};
    d = 2;
    cout << solution.findTheDistanceValue(arr1, arr2, d) << endl;
}
