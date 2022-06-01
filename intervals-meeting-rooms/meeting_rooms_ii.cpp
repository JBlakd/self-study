#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return 1;
        }

        // New paradigm: sort intervals by meeting start time
        // Credit: https://youtu.be/FdzJmTCVyJU?t=267
        // Iterate through both start and end points in order
        // When we encounter a start point, it means a meeting has behun. increment count
        // When we encounter an end point, it means a meeting has ended. decrement count
        // Return maximum count (max simultaneous meetings)
        // Note: A better way to achieve this is with a MinPQ<pair<time, type>>

        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> times;
        for (auto& interval : intervals) {
            times.emplace(interval[0], 's');
            times.emplace(interval[1], 'e');
        }

        int ret = 0;
        int num_simultaneous_meetings = 0;
        while (!times.empty()) {
            if (times.top().second == 's') {
                ++num_simultaneous_meetings;
            } else {
                --num_simultaneous_meetings;
            }

            ret = max(ret, num_simultaneous_meetings);
            times.pop();
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
    vector<vector<int>> intervals;

    // 2
    intervals = {{2, 15}, {36, 45}, {9, 29}, {16, 23}, {4, 9}};
    cout << solution.minMeetingRooms(intervals) << endl;

    // 2
    intervals = {{2, 11}, {6, 16}, {11, 16}};
    cout << solution.minMeetingRooms(intervals) << endl;

    // 2
    intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << solution.minMeetingRooms(intervals) << endl;

    // 1
    intervals = {{7, 10}, {2, 4}};
    cout << solution.minMeetingRooms(intervals) << endl;
}
