#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) {
            return 1;
        }

        vector<int> ret(ratings.size(), 1);

        // forward pass
        for (int i = 0; i < ret.size(); ++i) {
            if (i != 0 && i != ret.size() - 1) {
                if (ratings[i] > ratings[i - 1] && ratings[i] > ratings[i + 1]) {
                    ret[i] = max(ret[i - 1], ret[i + 1]) + 1;
                } else if (ratings[i] > ratings[i - 1]) {
                    ret[i] = ret[i - 1] + 1;
                } else if (ratings[i] > ratings[i + 1]) {
                    ret[i] = ret[i + 1] + 1;
                }
            } else if (i == 0 && ratings[i] > ratings[i + 1]) {
                ret[i] = ret[i + 1] + 1;
            } else if (i == ret.size() - 1 && ratings[i] > ratings[i - 1]) {
                ret[i] = ret[i - 1] + 1;
            }
        }

        // backward pass
        for (int i = ret.size() - 1; i >= 0; --i) {
            if (i != 0 && i != ret.size() - 1) {
                if (ratings[i] > ratings[i - 1] && ratings[i] > ratings[i + 1]) {
                    ret[i] = max(ret[i - 1], ret[i + 1]) + 1;
                } else if (ratings[i] > ratings[i - 1]) {
                    ret[i] = ret[i - 1] + 1;
                } else if (ratings[i] > ratings[i + 1]) {
                    ret[i] = ret[i + 1] + 1;
                }
            } else if (i == 0 && ratings[i] > ratings[i + 1]) {
                ret[i] = ret[i + 1] + 1;
            } else if (i == ret.size() - 1 && ratings[i] > ratings[i - 1]) {
                ret[i] = ret[i - 1] + 1;
            }
        }

        return accumulate(ret.begin(), ret.end(), 0);
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
    vector<int> ratings;
    int output;

    ratings = {7};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 1);

    ratings = {7, 7};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 2);

    ratings = {7, 2};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 3);

    ratings = {3, 5, 2, 6, 78, 9, 6, 4, 3, 4, 6, 8, 4, 4, 7, 8, 3, 2, 1, 3, 5, 4, 6};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 52);

    ratings = {3, 5, 8, 4, 4, 7, 8, 3, 2, 1, 3, 5, 4, 6};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 28);

    ratings = {4, 6, 7, 2};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 7);

    ratings = {4, 6, 1, 2};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 6);

    ratings = {7, 6, 7, 2};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 6);

    ratings = {1, 0, 2};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 5);

    ratings = {1, 2, 2};
    output = solution.candy(ratings);
    cout << output << '\n';
    assert(output == 4);

    cout << "Great success!" << '\n';
}
