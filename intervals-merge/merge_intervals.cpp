#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Custom lambda function enabling min priority queue to sort vectors based on size of first element
        auto cmp = [](vector<int> left, vector<int> right) { return (left[0] > right[0]); };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_pq(cmp);
        for (auto& interval : intervals) {
            min_pq.push(interval);
        }

        vector<vector<int>> ret;

        vector<int> merged_interval = min_pq.top();
        min_pq.pop();
        while (!min_pq.empty()) {
            vector<int> cur_interval = min_pq.top();
            min_pq.pop();

            if (cur_interval[0] <= merged_interval[1] && cur_interval[1] > merged_interval[1]) {
                // If cur_interval overlaps with existing interval, and cur_interval ends after existing
                merged_interval[1] = cur_interval[1];
            } else if (cur_interval[0] <= merged_interval[1] && cur_interval[1] <= merged_interval[1]) {
                // If existing interval completely encompasses cur_interval
                // do nothing
            }
            else {
                // No overlap, push previous merged_interval into ret
                ret.push_back(merged_interval);
                merged_interval = cur_interval;
            }

            // All cases have been covered. Only 3 cases as opposed to 6 because min_pq ensures intervals are sorted by start order

            // if (min_pq.empty()) {
            //     ret.push_back(merged_interval);
            // }
        }

        // Last one needs to be pushed
        ret.push_back(merged_interval);
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
    vector<vector<int>> intervals;
    vector<vector<int>> output;

    intervals = {};
    output = solution.merge(intervals);
    for (auto& vec : output) {
        print_vector(vec);
    }
    cout << endl;

    intervals = {{1, 4}};
    output = solution.merge(intervals);
    for (auto& vec : output) {
        print_vector(vec);
    }
    cout << endl;

    intervals = {{1, 4}, {0, 5}};
    output = solution.merge(intervals);
    for (auto& vec : output) {
        print_vector(vec);
    }
    cout << endl;

    intervals = {{1, 4}, {4, 5}};
    output = solution.merge(intervals);
    for (auto& vec : output) {
        print_vector(vec);
    }
    cout << endl;

    intervals = {{8, 10}, {1, 3}, {15, 18}, {2, 6}};
    output = solution.merge(intervals);
    for (auto& vec : output) {
        print_vector(vec);
    }
    cout << endl;
}
