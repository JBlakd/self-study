#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        auto cmp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (vector<int>& slot : slots1) {
            pq.emplace(slot);
        }
        for (vector<int>& slot : slots2) {
            pq.emplace(slot);
        }

        vector<int> last_removed = pq.top();
        pq.pop();
        while (!pq.empty()) {
            // calculate overlap time of last_removed
            bool replace_last_removed = false;
            int overlap_time;
            if (pq.top()[1] > last_removed[1]) {
                overlap_time = last_removed[1] - pq.top()[0];
                replace_last_removed = true;
            } else {
                overlap_time = pq.top()[1] - pq.top()[0];
            }

            if (overlap_time >= duration) {
                return {pq.top()[0], pq.top()[0] + duration};
            }

            if (replace_last_removed) {
                last_removed = pq.top();
            }
            pq.pop();
        }

        return {};
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
    vector<vector<int>> slots1;
    vector<vector<int>> slots2;
    int duration;
    vector<int> output;

    slots1 = {{10, 60}};
    slots2 = {{12, 17}, {21, 50}};
    duration = 8;
    output = solution.minAvailableDuration(slots1, slots2, duration);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{21, 29}));

    slots1 = {{0, 2}};
    slots2 = {{1, 3}};
    duration = 1;
    output = solution.minAvailableDuration(slots1, slots2, duration);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{1, 2}));

    slots1 = {{10, 50}, {60, 120}, {140, 210}};
    slots2 = {{0, 15}, {60, 70}};
    duration = 12;
    output = solution.minAvailableDuration(slots1, slots2, duration);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{}));

    slots1 = {{10, 50}, {60, 120}, {140, 210}};
    slots2 = {{0, 15}, {60, 70}};
    duration = 8;
    output = solution.minAvailableDuration(slots1, slots2, duration);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{60, 68}));

    cout << "Great success!" << '\n';
}
