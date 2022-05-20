#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<unordered_set<int>> frequencies(nums.size() + 1);
        unordered_map<int, int> each_number_freq;

        for (int num : nums) {
            // Update frequency map
            if (each_number_freq.find(num) == each_number_freq.end()) {
                each_number_freq.emplace(num, 1);
            } else {
                ++each_number_freq[num];
            }

            // Update vector of sets
            frequencies[each_number_freq[num]].insert(num);
            if (frequencies[each_number_freq[num] - 1].find(num) != frequencies[each_number_freq[num] - 1].end()) {
                frequencies[each_number_freq[num] - 1].erase(num);
            }
        }

        vector<int> ret;
        for (int i = frequencies.size() - 1; i > 0; --i) {
            if (frequencies[i].empty()) {
                continue;
            }
            while (!frequencies[i].empty()) {
                int val = *frequencies[i].begin();
                ret.push_back(val);
                frequencies[i].erase(val);
                --k;
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
