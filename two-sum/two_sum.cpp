#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_idx_map;

        for (int i = 0; i < nums.size(); i++) {
            // If the complement is not in map, add the current number to the map
            if (num_to_idx_map.find(target - nums[i]) == num_to_idx_map.end()) {
                num_to_idx_map.insert({nums[i], i});
            } else {
                return {i, num_to_idx_map.at(target - nums[i])};
            }
        }

        throw runtime_error("Solution not found in an input where there should be exactly 1 solution.");
    }
};

int main() {
    Solution solution;
    vector<int> input;
    int target;
    vector<int> output;

    input = {2, 7, 11, 15};
    target = 9;
    output = solution.twoSum(input, target);
    cout << "[" << output[0] << "," << output[1] << "]" << endl;

    input = {3,2,4};
    target = 6;
    output = solution.twoSum(input, target);
    cout << "[" << output[0] << "," << output[1] << "]" << endl;

    input = {3,3};
    target = 6;
    output = solution.twoSum(input, target);
    cout << "[" << output[0] << "," << output[1] << "]" << endl;
}
