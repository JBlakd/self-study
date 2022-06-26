#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_points = 0;
        int window_points = 0;

        for (int i = 0; i < cardPoints.size(); ++i) {
            total_points += cardPoints[i];
            window_points += cardPoints[i];
        }

        if (k == cardPoints.size()) {
            return total_points;
        }

        int window_start = 0;
        int window_end = cardPoints.size() - 1;
        for (; window_end >= cardPoints.size() - k; --window_end) {
            window_points -= cardPoints[window_end];
        }

        int min_window_points = window_points;

        // slide the window
        do {
            ++window_start;
            ++window_end;

            window_points -= cardPoints[window_start - 1];
            window_points += cardPoints[window_end];

            min_window_points = min(min_window_points, window_points);
        } while (window_end < cardPoints.size() - 1);

        return total_points - min_window_points;
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
    vector<int> cardPoints;
    int k;
    int output;

    cardPoints = {9, 7, 7, 9, 7, 7, 9};
    k = 7;
    output = solution.maxScore(cardPoints, k);
    cout << output << '\n';
    assert(output == 55);

    cardPoints = {1, 2, 3, 4, 5, 6, 1};
    k = 3;
    output = solution.maxScore(cardPoints, k);
    cout << output << '\n';
    assert(output == 12);

    cardPoints = {2, 2, 2};
    k = 2;
    output = solution.maxScore(cardPoints, k);
    cout << output << '\n';
    assert(output == 4);

    cout << "Great success!" << '\n';
}
