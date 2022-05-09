#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // construct monotonic decreasing stack using nums2 as input
        // if a current element causes a pop, any popped elements from the stack should be added to the map.
        // Key: popped element. Value: current element. The value will be the next greatest element of the key.
        // loop through nums1. For each num1, its output is the value, or -1 if key doesn't exist
        stack<int> mono_decrease;
        unordered_map<int, int> map;

        for (int num2 : nums2) {
            // Check if we need to pop
            // Need to pop while top is less than incoming number
            while (!mono_decrease.empty() && mono_decrease.top() < num2) {
                map.emplace(mono_decrease.top(), num2);
                mono_decrease.pop();
            }
            mono_decrease.push(num2);
        }

        vector<int> ret(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            if (map.find(nums1[i]) != map.end()) {
                ret[i] = map.at(nums1[i]);
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
    vector<int> nums1;
    vector<int> nums2;
    vector<int> output;

    // {6,9,7}
    nums1 = {4, 3, 6};
    nums2 = {4, 6, 7, 1, 3, 9};
    output = solution.nextGreaterElement(nums1, nums2);
    print_vector(output);
    cout << endl;
}
