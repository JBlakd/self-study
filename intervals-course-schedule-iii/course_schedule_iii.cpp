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
        // preferentially sort the courses by ascending duration, and then by ascending deadline
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            // should return true if a is ordered before b
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int current_time_taken = 0;
        int ret1 = 0;
        for (vector<int>& course : courses) {
            // attempt to fit current course into schedule
            if (current_time_taken + course[0] <= course[1]) {
                // if this course fits into its own deadline
                current_time_taken += course[0];
                ++ret1;
            }
        }

        // preferentially sort the courses by ascending deadline, and then by ascending duration
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            // should return true if a is ordered before b
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        current_time_taken = 0;
        int ret2 = 0;
        for (vector<int>& course : courses) {
            // attempt to fit current course into schedule
            if (current_time_taken + course[0] <= course[1]) {
                // if this course fits into its own deadline
                current_time_taken += course[0];
                ++ret2;
            }
        }

        return max(ret1, ret2);
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

    courses = {{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 4);

    courses = {{5, 15}, {3, 19}, {6, 7}, {2, 10}, {5, 16}, {8, 14}, {10, 11}, {2, 19}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 5);

    courses = {{5, 5}, {4, 6}, {2, 6}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 2);

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
