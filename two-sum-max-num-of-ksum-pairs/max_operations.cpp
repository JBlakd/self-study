#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> val_to_indices;
        int num_operations = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // if nums[i] >= k, then no complement for nums[i] exists (no zero or negative values in the array)
            if (nums[i] >= k) {
                continue;
            }

            if (val_to_indices.find(k - nums[i]) == val_to_indices.end()) {
                if (val_to_indices.find(nums[i]) == val_to_indices.end()) {
                    // if vector at the key doesn't exist, create vector and insert first val
                    vector<int> temp = {i};
                    val_to_indices.insert(make_pair(nums[i], temp));
                } else {
                    // else if vector at the key already exists, insert val; into the existing vector
                    val_to_indices.at(nums[i]).push_back(i);
                    // val_to_index.insert(make_pair(nums[i], i));
                }

            } else {
                if (val_to_indices.at(k - nums[i]).size() > 1) {
                    // If vector at key has more than 1 elements, pop
                    val_to_indices.at(k - nums[i]).pop_back();
                } else {
                    // else if vector at key has 1 element, erase the whole key
                    val_to_indices.erase(k - nums[i]);
                }
                ++num_operations;
            }
        }

        return num_operations;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int k;

    // 4
    nums = {2, 5, 4, 4, 1, 3, 4, 4, 1, 4, 4, 1, 2, 1, 2, 2, 3, 2, 4, 2};
    k = 3;
    cout << solution.maxOperations(nums, k) << endl;

    // 2
    nums = {1, 2, 3, 4};
    k = 5;
    cout << solution.maxOperations(nums, k) << endl;

    // 1
    nums = {3, 1, 3, 4, 3};
    k = 5;
    cout << solution.maxOperations(nums, k) << endl;

    // 2
    nums = {3, 1, 4, 9, 6, 8, 2, 3};
    k = 5;
    cout << solution.maxOperations(nums, k) << endl;
}
