#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int max_height = horizontalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            max_height = max(max_height, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        max_height = max(max_height, h - horizontalCuts.back());

        int max_width = verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); ++i) {
            max_width = max(max_width, verticalCuts[i] - verticalCuts[i - 1]);
        }
        max_width = max(max_width, w - verticalCuts.back());

        return (int)(((uint64_t)max_width * max_height) % (1000000000 + 7));
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
    int h;
    int w;
    vector<int> horizontalCuts;
    vector<int> verticalCuts;
    int output;

    h = 5;
    w = 4;
    horizontalCuts = {3, 1};
    verticalCuts = {1};
    output = solution.maxArea(h, w, horizontalCuts, verticalCuts);
    cout << output << '\n';
    assert(output == 6);

    h = 5;
    w = 4;
    horizontalCuts = {1, 2, 4};
    verticalCuts = {1, 3};
    output = solution.maxArea(h, w, horizontalCuts, verticalCuts);
    cout << output << '\n';
    assert(output == 4);

    cout << "Great success!" << '\n';
}
