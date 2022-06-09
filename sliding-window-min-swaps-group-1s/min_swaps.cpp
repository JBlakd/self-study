#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSwaps(vector<int>& data) {
        // count number of 1's
        int count = 0;
        for (int& element : data) {
            if (element == 1) {
                ++count;
            }
        }
        if (count < 1) {
            return 0;
        }

        // Create the window, track number of 0's in the window
        int lo = 0;
        int hi = count - 1;
        // Repurpose the count variable
        count = 0;
        for (int i = lo; i <= hi; ++i) {
            if (data[i] == 0) {
                ++count;
            }
        }
        int ret = count;
        ++lo;
        ++hi;

        // Slide the window
        while (hi < data.size()) {
            if (data[hi] == 0) {
                ++count;
            }

            if (data[lo - 1] == 0) {
                --count;
            }

            ret = min(ret, count);

            ++lo;
            ++hi;
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
    vector<int> data;

    // 1
    data = {1, 0, 1, 0, 1};
    cout << solution.minSwaps(data) << '\n';

    // 0
    data = {0, 0, 0, 1, 0};
    cout << solution.minSwaps(data) << '\n';

    // 3
    data = {1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1};
    cout << solution.minSwaps(data) << '\n';
}
