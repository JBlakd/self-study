#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> ret;

        vector<int> merged_interval = {100001, -1};
        bool found_min_merged = false;
        for (int i = 0; i < intervals.size(); i++) {
            auto interval = intervals[i];
            if (interval[1] < newInterval[0]) {
                // left of newInterval
                ret.push_back(interval);

                // If never encountered interesecting interval and is last element
                if (!found_min_merged && i == intervals.size() - 1) {
                    ret.push_back(newInterval);
                }
            } else if (interval[0] > newInterval[1]) {
                // right of newInterval
                // If never encountered interesecting interval
                if (!found_min_merged) {
                    found_min_merged = true;
                    ret.push_back(newInterval);
                }

                ret.push_back(interval);
            } else {
                // intersects with newInterval
                if (!found_min_merged) {
                    found_min_merged = true;
                    merged_interval[0] = min(interval[0], newInterval[0]);
                }

                // If next interval is null or is a right interval, then we have to process last intersection interval
                if (i == intervals.size() - 1 || intervals[i + 1][0] > newInterval[1]) {
                    merged_interval[1] = max(interval[1], newInterval[1]);
                    ret.push_back(merged_interval);
                }
            }
        }

        intervals = ret;
        return intervals;
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
    vector<int> newInterval;
    vector<vector<int>> output;

    intervals = {{2, 5}, {6, 7}, {8, 9}};
    newInterval = {0, 1};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;

    intervals = {};
    newInterval = {1, 5};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;

    intervals = {{4, 6}};
    newInterval = {1, 5};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;

    intervals = {{2, 3}};
    newInterval = {1, 5};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;

    intervals = {{1, 3}};
    newInterval = {4, 5};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;

    intervals = {{1, 3}, {6, 9}};
    newInterval = {4, 5};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;

    intervals = {{1, 3}, {6, 9}};
    newInterval = {2, 7};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;

    intervals = {{1, 3}, {6, 9}};
    newInterval = {2, 5};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;

    intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    newInterval = {4, 8};
    output = solution.insert(intervals, newInterval);
    cout << "{";
    for (auto interval : output) {
        print_vector(interval);
        cout << ", ";
    }
    cout << "}" << endl;
}
