#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // preferentially sort the courses by ascending deadline
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            // should return true if a is ordered before b
            return a[1] < b[1];
        });

        // Iterate through our ascending-deadline courses, pushing each into a priority queue with the longest courses being on top
        // If the sum of the courses' duration in our priority queue ever exceeds the deadline of the course we're currently considering
        // pop until the sum fits within the deadline
        int enqueued_duration = 0;
        priority_queue<int> durations;
        for (auto& course : courses) {
            // just skip impossible courses mate
            if (course[1] < course[0]) {
                continue;
            }

            int& current_deadline = course[1];

            // push into priority queue
            durations.emplace(course[0]);
            enqueued_duration += course[0];

            while (enqueued_duration > current_deadline) {
                enqueued_duration -= durations.top();
                durations.pop();
            }
        }

        return durations.size();
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
    vector<vector<int>> courses;
    int output;

    courses = {{100, 2}, {32, 50}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 1);

    courses = {{5, 5}, {4, 6}, {2, 6}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 2);

    courses = {{5, 15}, {3, 19}, {6, 7}, {2, 10}, {5, 16}, {8, 14}, {10, 11}, {2, 19}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 5);

    courses = {{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 4);

    courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 3);

    courses = {{1, 2}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 1);

    courses = {{3, 2}, {4, 3}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 0);

    cout << "Great success!" << '\n';
}
