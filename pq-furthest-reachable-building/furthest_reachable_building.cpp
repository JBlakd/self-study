#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if (heights.size() == 1) {
            return 0;
        }

        priority_queue<int, vector<int>, greater<int>> used_ladder_heights;
        int i = 0;
        for (; i < heights.size() - 1; ++i) {
            int jump_height = heights[i + 1] - heights[i];
            if (jump_height <= 0) {
                continue;
            }

            used_ladder_heights.emplace(jump_height);

            if (used_ladder_heights.size() <= ladders) {
                continue;
            }

            bricks -= used_ladder_heights.top();
            used_ladder_heights.pop();

            if (bricks < 0) {
                break;
            }
        }

        return i;
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

    heights = {4, 2, 7, 6, 9, 14, 12};
    bricks = 5;
    ladders = 1;
    output = solution.furthestBuilding(heights, bricks, ladders);
    cout << output << '\n';
    assert(output == 4);

    heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    bricks = 10;
    ladders = 2;
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

    cout << "Great success!" << '\n';
}
