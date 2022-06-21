#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if (heights.size() == 1) {
            return 0;
        }

        // if (bricks == 0) {
        //     int i = 0;
        //     for (; i < heights.size(); ++i) {
        //         if (heights[i + 1] - heights[i] > bricks) {
        //             break;
        //         } else {
        //             bricks -= heights[i + 1] - heights[i];
        //         }
        //     }
        //     return i;
        // }

        vector<int> jumps(heights.size(), 0);
        vector<int> jumps_prefix_sum(heights.size(), 0);
        //                 <jump_height, dest_index>
        priority_queue<pair<int, int>> highest_jumps;

        for (int i = 1; i < heights.size(); ++i) {
            // populating heights and pq
            if (heights[i] > heights[i - 1]) {
                jumps[i] = heights[i] - heights[i - 1];
            }
            if (jumps[i] > 0) {
                highest_jumps.emplace(jumps[i], i);
            }

            // populating prefix sum of heights
            jumps_prefix_sum[i] = jumps_prefix_sum[i - 1] + jumps[i];
        }

        // find at which index we start jumping
        priority_queue<int, vector<int>, greater<int>> definite_jumps;
        while (!highest_jumps.empty() && jumps_prefix_sum[highest_jumps.top().second] > bricks) {
            definite_jumps.emplace(highest_jumps.top().second);
            highest_jumps.pop();
        }
        definite_jumps.emplace(highest_jumps.top().second);

        // start traversing
        int ret = 0;
        for (; ret < heights.size() - 1; ++ret) {
            if (definite_jumps.empty() || ladders == 0 || ret + 1 != definite_jumps.top()) {
                // use bricks
                if (jumps[ret + 1] <= bricks) {
                    bricks -= jumps[ret + 1];
                } else {
                    break;
                }
            } else {
                // use ladders
                if (ladders > 0) {
                    --ladders;
                    definite_jumps.pop();
                } else {
                    break;
                }
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
    vector<int> heights;
    int bricks;
    int ladders;
    int output;

    heights = {1, 13, 1, 1, 13, 5, 11, 11};
    bricks = 10;
    ladders = 8;
    output = solution.furthestBuilding(heights, bricks, ladders);
    cout << output << '\n';
    assert(output == 7);

    heights = {17, 16, 5, 10, 10, 14, 7};
    bricks = 74;
    ladders = 6;
    output = solution.furthestBuilding(heights, bricks, ladders);
    cout << output << '\n';
    assert(output == 6);

    heights = {14, 3, 19, 3};
    bricks = 17;
    ladders = 0;
    output = solution.furthestBuilding(heights, bricks, ladders);
    cout << output << '\n';
    assert(output == 3);

    heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    bricks = 10;
    ladders = 2;
    output = solution.furthestBuilding(heights, bricks, ladders);
    cout << output << '\n';
    assert(output == 7);

    heights = {4, 2, 7, 6, 9, 14, 12};
    bricks = 5;
    ladders = 1;
    output = solution.furthestBuilding(heights, bricks, ladders);
    cout << output << '\n';
    assert(output == 4);

    cout << "Great success!" << '\n';
}
