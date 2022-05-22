#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int totalStrength(vector<int>& strength) {
        // cocktail shaker approach
        bool forward = true;
        int front_idx = 0;
        int back_idx = 0;
        int cur_window_size = 1;
        int min = strength[0];
        int cur_total = strength[0];
        int ret = 0;
        while (front_idx - back_idx < strength.size()) {
            ret += min * cur_total;

            // move window
            if (forward) {
                if (front_idx == strength.size() - 1) {
                    forward = false;
                    ++cur_window_size;
                    front_idx = strength.size() - 1 - cur_window_size;
                    back_idx = strength.size() - 1;
                } else {
                    ++front_idx;
                    ++back_idx;
                }
            } else {
                if (front_idx == 0) {
                    forward = true;
                    front_idx = cur_window_size;
                    ++cur_window_size;
                    back_idx = 0;
                } else {
                    --front_idx;
                    --back_idx;
                }
            }
        }
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
