#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return 0;
        }

        // This is the inverse of the classic Interval Scheduling problem
        // To calculate the max number of non-conflicting intervals, sort the intervals by ascending finish time,
        // then sequentially include non-conflicting intervals
        // The minimum number of intervals we have to erase to resolve all conflicts is therefore the inverse of the INterval Scheduling problem.

        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) { return i1[1] < i2[1]; });

        int num_nonconflicting = 1;
        int last_valid_index = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[last_valid_index][1]) {
                continue;
            }
            ++num_nonconflicting;
            last_valid_index = i;
        }

        return intervals.size() - num_nonconflicting;
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

    // 1
    intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;

    // 2
    intervals = {{1, 2}, {1, 2}, {1, 2}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;

    // 0
    intervals = {{1, 2}, {2, 3}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;
}
