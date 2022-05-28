#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        // Time should be O(n), Space should be O(1)
        // Resize nums to be 1 bigger, populate the extra space with -1
        nums.resize(nums.size() + 1, -1);

        for (int i = 0; i < nums.size(); ++i) {
            while (true) {
                if (nums[i] == -1 || nums[i] == i) {
                    break;
                }
                swap(i, nums[i], nums);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -1) {
                return i;
            }
        }

        return -1;
    }

   private:
    void swap(int idx1, int idx2, vector<int>& nums) {
        if (idx1 == idx2) {
            return;
        }
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
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

    // 2
    nums = {0, 3, 5, 8, 4, 6, 1, 9, 7};
    cout << solution.missingNumber(nums) << endl;

    // 8
    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << solution.missingNumber(nums) << endl;
}
