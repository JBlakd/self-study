#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int paintHouses(vector<vector<int>> input) {
        if (input.size() == 1) {
            return min(min(input[0][0], input[0][1]), input[0][2]);
        }

        for (int i = 1; i < input.size(); i++) {
            input[i][0] += min(input[i - 1][1], input[i - 1][2]);
            input[i][1] += min(input[i - 1][0], input[i - 1][2]);
            input[i][2] += min(input[i - 1][1], input[i - 1][0]);
        }

        return min(min(input.back()[0], input.back()[1]), input.back()[2]);
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
    vector<vector<int>> input;
    int output;

    input = {{1, 2, 3}, {1, 2, 2}};
    output = solution.paintHouses(input);
    cout << output << '\n';
    assert(output == 3);

    input = {{8, 2, 6}, {4, 9, 3}, {3, 7, 2}, {2, 4, 1}, {1, 4, 1}};
    output = solution.paintHouses(input);
    cout << output << '\n';
    assert(output == 10);

    cout << "Great success!" << '\n';
}
