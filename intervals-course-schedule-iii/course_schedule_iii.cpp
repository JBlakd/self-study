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
        // remove invalid courses (duration longer than the deadline)
        remove_if(courses.begin(), courses.end(), [](vector<int>& course) {
            return course[1] < course[0];
        });

        // After this check, we should have more than 1 courses to consider
        if (courses.size() <= 1) {
            return courses.size();
        }

        // preferentially sort the courses by ascending deadline, and then by ascending duration
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            // should return true if a is ordered before b
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });

        int last_course_start = 0;
        int total_time_taken = courses[0][0];
        int ret = 1;
        for (int i = 1; i < courses.size(); ++i) {
            // replace the last course with the upcoming course if the upcoming course could do better than the last course
            // in terms of lessening the total_time_taken
            if (last_course_start + courses[i][0] < total_time_taken) {
                // replace
                total_time_taken = last_course_start + courses[i][0];
            } else {
                // reject the next course if it doesn't even fit into its own deadline
                if (total_time_taken + courses[i][0] > courses[i][1]) {
                    continue;
                }
                last_course_start = total_time_taken;
                total_time_taken = last_course_start + courses[i][0];
                ++ret;
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
    vector<vector<int>> courses;
    int output;

    courses = {{5, 15}, {3, 19}, {6, 7}, {2, 10}, {5, 16}, {8, 14}, {10, 11}, {2, 19}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 5);

    courses = {{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
    output = solution.scheduleCourse(courses);
    cout << output << '\n';
    assert(output == 4);

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
