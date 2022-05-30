#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == numeric_limits<int>::min() && divisor == -1) {
            return numeric_limits<int>::max();
        }

        bool is_negative = ((dividend & (1 << 31)) ^ (divisor & (1 << 31)));
        // cout << (is_negative ? "is negative" : "is not negative") << endl;

        // Get unsigned positive values of dividend and divisor
        uint32_t dividend_pos = abs(dividend);
        uint32_t divisor_pos = abs(divisor);

        // See how many times we can subtract divisor from dividend without going below zero
        int ret = 0;
        while (dividend_pos >= divisor_pos) {
            dividend_pos -= divisor_pos;
            ++ret;
        }

        // Instead of repeated subtractions. We keep doubling the divisor until it cannot be doubled anymore, and then

        // Convert the answer into negative if necessary
        if (is_negative) {
            ret = ~ret + 1;
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
    int dividend;
    int divisor;

    dividend = -2147483648;
    divisor = 1;
    cout << solution.divide(dividend, divisor) << endl;

    dividend = -10;
    divisor = 3;
    cout << solution.divide(dividend, divisor) << endl;

    dividend = 111;
    divisor = 7;
    cout << solution.divide(dividend, divisor) << endl;

    dividend = 7;
    divisor = -3;
    cout << solution.divide(dividend, divisor) << endl;

    dividend = 65;
    divisor = 58;
    cout << solution.divide(dividend, divisor) << endl;

    dividend = -2147483648;
    divisor = -1;
    cout << solution.divide(dividend, divisor) << endl;

    dividend = 65;
    divisor = 7;
    cout << solution.divide(dividend, divisor) << endl;
}
