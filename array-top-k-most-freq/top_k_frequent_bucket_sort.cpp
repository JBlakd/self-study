#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> frequencies(nums.size() + 1);
        unordered_map<int, int> each_number_freq;

        for (int num : nums) {
            // Update frequency map
            ++each_number_freq[num];
        }

        // populate bucket
        for (auto frequency : each_number_freq) {
            frequencies[frequency.second].push_back(frequency.first);
        }

        vector<int> ret;
        for (int i = frequencies.size() - 1; i > 0; --i) {
            if (frequencies[i].empty()) {
                continue;
            }
            for (int number : frequencies[i]) {
                ret.push_back(number);
                k--;
                if (k == 0) {
                    return ret;
                }
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
    vector<int> nums;
    int k;
    vector<int> output;

    nums = {1, 2};
    k = 2;
    output = solution.topKFrequent(nums, k);
    print_vector(output);
    cout << endl;

    nums = {69};
    k = 1;
    output = solution.topKFrequent(nums, k);
    print_vector(output);
    cout << endl;

    nums = {1, 1, 1, 2, 2, 3};
    k = 2;
    output = solution.topKFrequent(nums, k);
    print_vector(output);
    cout << endl;

    nums = {1, 2, 1, 2, 1, 3};
    k = 2;
    output = solution.topKFrequent(nums, k);
    print_vector(output);
    cout << endl;
}
