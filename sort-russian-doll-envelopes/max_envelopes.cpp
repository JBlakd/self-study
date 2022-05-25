#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 1) {
            return 1;
        }

        // Comparator to sort first by ascending width, and then descending height
        // Reason for descending height is because upon encountering multiple envelopes of the same width,
        // we want to consider only one of these envelopes. If we can only pick one, then the best one to
        // consider would be the biggest one.
        auto asc_width_dsc_height = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        };

        // sort by ascending width then height
        sort(envelopes.begin(), envelopes.end(), asc_width_dsc_height);

        // Find the longest increasing subsequence based on height
        // No need to consider width, the sort already took care of it (source: trust me bro)
        vector<int> subsequence(1, envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); ++i) {
            if (envelopes[i][1] > subsequence.back()) {
                subsequence.push_back(envelopes[i][1]);
            } else {
                auto it = lower_bound(subsequence.begin(), subsequence.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }

        return subsequence.size();
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
    vector<vector<int>> envelopes;

    // 3
    envelopes = {{46, 89}, {50, 53}, {52, 68}, {72, 45}, {77, 81}};
    cout << solution.maxEnvelopes(envelopes) << '\n';

    // 5
    envelopes = {{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380}};
    cout << solution.maxEnvelopes(envelopes) << '\n';

    // 3
    envelopes = {{17, 15}, {17, 18}, {2, 8}, {7, 2}, {17, 2}, {17, 8}, {6, 15}};
    cout << solution.maxEnvelopes(envelopes) << '\n';

    // 3
    envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << solution.maxEnvelopes(envelopes) << '\n';

    // 1
    envelopes = {{1, 1}, {1, 1}, {1, 1}};
    cout << solution.maxEnvelopes(envelopes) << '\n';
}
