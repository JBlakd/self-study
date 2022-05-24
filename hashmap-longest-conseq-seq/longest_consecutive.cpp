#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_map<int, bool> hashmap;

        for (auto& num : nums) {
            hashmap[num] = false;
        }

        int longest_found = 1;

        for (auto& [num, explored] : hashmap) {
            if (explored) {
                continue;
            }

            explored = true;

            int elements_after = 0;
            while (hashmap.find(num + elements_after + 1) != hashmap.end()) {
                ++elements_after;
                hashmap.at(num + elements_after) = true;
            }

            int elements_before = 0;
            while (hashmap.find(num - elements_before - 1) != hashmap.end()) {
                ++elements_before;
                hashmap.at(num - elements_before) = true;
            }
            longest_found = max(longest_found, elements_before + elements_after + 1);
        }

        return longest_found;
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

    nums = {100, 4, 200, 1, 3, 2};
    cout << solution.longestConsecutive(nums) << '\n';

    nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << solution.longestConsecutive(nums) << '\n';
}
