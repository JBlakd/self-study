#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> freq_pq;
        unordered_map<int, int> freq_map;

        for (int i = 0; i < nums.size(); i++) {
            if (freq_map.find(nums[i]) == freq_map.end()) {
                freq_map.insert(make_pair(nums[i], 1));
            } else {
                ++freq_map.at(nums[i]);
            }
        }

        for (auto entry : freq_map) {
            freq_pq.push(make_pair(entry.second, entry.first));
        }

        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(freq_pq.top().second);
            freq_pq.pop();
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> input;
    int k;
    vector<int> output;

    input = {6, 2, 8, 3, 6, 3, 2, 6, 6, 2};  // 6,6,6,6,2,2,2,3,3,8
    k = 2;
    output = solution.topKFrequent(input, k);
    for (auto val : output) {
        cout << val << ", ";
    }
    cout << endl;

    input = {-1, -1};
    k = 1;
    output = solution.topKFrequent(input, k);
    for (auto val : output) {
        cout << val << ", ";
    }
    cout << endl;

    input = {1, 1, 1, 2, 2, 3};
    k = 2;
    output = solution.topKFrequent(input, k);
    for (auto val : output) {
        cout << val << ", ";
    }
    cout << endl;

    input = {1};
    k = 1;
    output = solution.topKFrequent(input, k);
    for (auto val : output) {
        cout << val << ", ";
    }
    cout << endl;
}
