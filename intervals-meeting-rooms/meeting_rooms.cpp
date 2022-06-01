#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return true;
        }

        // sort intervals by ascending finish time
        // as soon as we encounter an interval which begins before the previous could finish, return false
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return true;
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
}
