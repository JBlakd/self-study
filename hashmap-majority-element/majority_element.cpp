#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        // <num, count>
        unordered_map<int, int> hashmap;

        for (auto num : nums) {
            ++hashmap[num];
        }

        int half = nums.size() / 2;

        for (auto& [num, count] : hashmap) {
            if (count > half) {
                return num;
            }
        }

        return 0;
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

    // 69
    nums = {69};
    cout << solution.majorityElement(nums) << '\n';

    // 3
    nums = {3, 2, 3};
    cout << solution.majorityElement(nums) << '\n';

    // 2
    nums = {2, 2, 1, 1, 1, 2, 2};
    cout << solution.majorityElement(nums) << '\n';
}
