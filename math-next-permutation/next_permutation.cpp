#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }

        // find first non-increasing element, counting backwards
        int pivot = nums.size() - 2;
        while (pivot >= -1) {
            if (nums[pivot] < nums[])
                --pivot;
        }
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
}
