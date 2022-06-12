#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        // O(n)

        // -1 denotes unexplored
        vector<int> water(height.size(), -1);
        // pre-process water vector: edge-adjacent columns always hold no water
        int left_limit = 0;
        while (left_limit < height.size()) {
            if (height[left_limit] != 0) {
                break;
            }
            water[left_limit] = 0;
            ++left_limit;
        }
        if (left_limit >= height.size() - 1) {
            return 0;
        }
        int right_limit = height.size() - 1;
        while (right_limit >= 0) {
            if (height[right_limit] != 0) {
                break;
            }
            water[right_limit] = 0;
            --right_limit;
        }
        if (right_limit <= 0) {
            return 0;
        }

        // initiate scan from left
        int lo = left_limit;
        int hi = left_limit + 1;
        int cur_highest = height[lo];
        while (hi < height.size()) {
            if (height[hi] >= cur_highest) {
                cur_highest = height[hi];
                int cur_lo_height = height[lo];

                // fill water
                while (lo < hi) {
                    // no negatives allowed. If negative, make it 0
                    water[lo] = max(0, cur_lo_height - height[lo]);
                    ++lo;
                }
            }
            ++hi;
        }

        // initiate scan from right
        lo = right_limit - 1;
        hi = right_limit;
        cur_highest = height[hi];
        while (lo >= 0) {
            if (water[lo] != -1) {
                --lo;
                hi = lo;
                continue;
            }

            if (height[lo] >= cur_highest) {
                cur_highest = height[lo];
                int cur_hi_height = height[hi];

                // fill water
                while (hi > lo) {
                    // no negatives allowed. If negative, make it 0
                    water[hi] = max(0, cur_hi_height - height[hi]);
                    --hi;
                }
            }
            --lo;
        }

        // count water;
        int ret = 0;
        for (int water_level : water) {
            if (water_level != -1) {
                ret += water_level;
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
    vector<int> height;
    int output;

    // 0
    height = {1, 2, 3, 1};
    output = solution.trap(height);
    cout << output << '\n';
    assert(output == 0);

    // 0
    height = {1, 1, 1, 1};
    output = solution.trap(height);
    cout << output << '\n';
    assert(output == 0);

    // 0
    height = {0, 0, 0, 0};
    output = solution.trap(height);
    cout << output << '\n';
    assert(output == 0);

    // 0
    height = {0};
    output = solution.trap(height);
    cout << output << '\n';
    assert(output == 0);

    // 0
    height = {1};
    output = solution.trap(height);
    cout << output << '\n';
    assert(output == 0);

    // 5
    height = {3, 2, 4, 4, 3, 2, 4, 2, 3};
    output = solution.trap(height);
    cout << output << '\n';
    assert(output == 5);

    // 6
    height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    output = solution.trap(height);
    cout << output << '\n';
    assert(output == 6);

    // 9
    height = {4, 2, 0, 3, 2, 5};
    output = solution.trap(height);
    cout << output << '\n';
    assert(output == 9);
}
