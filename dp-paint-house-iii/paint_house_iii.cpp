#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // int base_hoods = 0;
        // for (int i = 1; i < houses.size(); ++i) {
        //     if (houses[i] != houses[i-1]) {
        //         ++base_hoods;
        //     }
        // }

        // m        == rows     == number of houses
        // n        == cols     == number of colours
        // target   == depth    == number of neighbourhoods which exist if I paint house at row with the colour at col
        // target + 1 due to the possibility for 0 neighbourhoods
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target + 1, 0)));

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                for (int depth = row; depth <= row + 1; ++depth) {
                    if (houses[row] == 0) {
                        // increase a hood by choosing a different colour to the previous house
                        if (row != 0 && depth == row) {
                            // find the cheapest colour
                            int cheapest_colour_cost = 10001;
                            for (int i = 1; i < n; ++i) {
                                if (i == col) {
                                    // skip the same colour
                                    continue;
                                }
                                cheapest_colour_cost = min(cheapest_colour_cost, cost[row][i]);
                            }
                            dp[row][col][depth] = cheapest_colour_cost;
                        } else if (depth != row) {
                            // keep the hood the same by choosing the same colour as the previous house
                            dp[row][col][depth] = cost[row][col];
                        }
                    } else {
                        if (row == 0) {
                            dp[row][col][depth] = 0;
                        } else {
                            dp[row - 1][col][depth];
                        }
                    }
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

    /* UNIT TESTS HERE */

    cout << "Great success!" << '\n';
}
