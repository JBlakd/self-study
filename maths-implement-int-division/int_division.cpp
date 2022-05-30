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
        // dividend = (quotient) * divisor + remainder
        // The goal is to express the quotient in powers of 2
        // Find the maximum power of 2 that we could multiply divisor by and still be less than dividend
        int max_pow = 0;
        for (int i = 0; i <= 32; ++i) {
            if (i == 32 || divisor_pos << i > dividend_pos) {
                max_pow = i - 1;
                break;
            }
        }

        while (max_pow >= 0) {
            if (dividend_pos >= (divisor_pos << max_pow)) {
                dividend_pos -= (divisor_pos << max_pow);
                ret += (1 << max_pow);
            }
            --max_pow;
        }

        // Convert the answer into negative if necessary
        if (is_negative && !(ret & (1 << 31)) && ret != numeric_limits<int>::min()) {
            ret = ~ret + 1;
        }

        // Convert the answer into positive if necessary
        if (!is_negative && (ret & (1 << 31))) {
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

    // 1
    dividend = -2147483648;
    divisor = -2147483648;
    cout << solution.divide(dividend, divisor) << endl;

    // -1073741824
    dividend = -2147483648;
    divisor = 2;
    cout << solution.divide(dividend, divisor) << endl;

    // -2147483648
    dividend = -2147483648;
    divisor = 1;
    cout << solution.divide(dividend, divisor) << endl;

    // 0
    dividend = 65;
    divisor = 80;
    cout << solution.divide(dividend, divisor) << endl;

    // 1
    dividend = 65;
    divisor = 58;
    cout << solution.divide(dividend, divisor) << endl;

    // -3
    dividend = -10;
    divisor = 3;
    cout << solution.divide(dividend, divisor) << endl;

    // 15
    dividend = 111;
    divisor = 7;
    cout << solution.divide(dividend, divisor) << endl;

    // -2
    dividend = 7;
    divisor = -3;
    cout << solution.divide(dividend, divisor) << endl;

    // 2147483647
    dividend = -2147483648;
    divisor = -1;
    cout << solution.divide(dividend, divisor) << endl;

    // 9
    dividend = 65;
    divisor = 7;
    cout << solution.divide(dividend, divisor) << endl;
}
