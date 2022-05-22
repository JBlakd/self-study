#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() == 1) {
            return 0;
        }

        sort(stockPrices.begin(), stockPrices.end());

        int count = 1;
        double existing_gradient = (double)(stockPrices[1][1] - stockPrices[0][1]) / (double)(stockPrices[1][0] - stockPrices[0][0]);

        for (int i = 1; i < stockPrices.size() - 1; ++i) {
            // If gradient between current point and the next point does not equal to the existing_gradient
            double next_gradient = (double)(stockPrices[i + 1][1] - stockPrices[i][1]) / (double)(stockPrices[i + 1][0] - stockPrices[i][0]);
            // if (next_gradient != existing_gradient) {
            if (!almost_equal(existing_gradient, next_gradient, 2)) {
                existing_gradient = next_gradient;
                ++count;
            }
        }

        return count;
    }

   private:
    template <class T>
    typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    almost_equal(T x, T y, int ulp) {
        // the machine epsilon has to be scaled to the magnitude of the values used
        // and multiplied by the desired precision in ULPs (units in the last place)
        return std::fabs(x - y) <= std::numeric_limits<T>::epsilon() * std::fabs(x + y) * ulp
               // unless the result is subnormal
               || std::fabs(x - y) < std::numeric_limits<T>::min();
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
    vector<vector<int>> stockPrices;

    stockPrices = {{1, 1000000000}, {1000000000, 1000000000}, {999999999, 1}, {2, 999999999}};
    cout << solution.minimumLines(stockPrices) << endl;

    stockPrices = {{83, 35}, {79, 51}, {61, 48}, {54, 87}, {44, 93}, {22, 5}, {87, 28}, {64, 8}, {89, 78}, {62, 83}, {58, 72}, {48, 7}, {97, 16}, {27, 100}, {65, 48}, {11, 31}, {29, 76}, {93, 29}, {72, 59}, {73, 74}, {9, 90}, {66, 81}, {12, 8}, {86, 80}, {84, 43}, {36, 63}, {80, 45}, {81, 88}, {95, 5}, {40, 59}};
    cout << solution.minimumLines(stockPrices) << endl;

    stockPrices = {{1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 2}, {8, 1}};
    cout << solution.minimumLines(stockPrices) << endl;

    stockPrices = {{3, 4}, {1, 2}, {7, 8}, {2, 3}};
    cout << solution.minimumLines(stockPrices) << endl;

    stockPrices = {{1, 0}, {2, 1}, {3, 0}, {4, 1}, {5, 0}};
    cout << solution.minimumLines(stockPrices) << endl;
}
