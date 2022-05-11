#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countVowelStrings(int n) {
        // Intuitive one-liner permutation solution

        // We are simply working with a base 5 counting system.
        // Think hexadecimal, but base 5 instead of 16. This decimal, but base 5 instead of 10.
        // In this counting system, how many numbers contain n digits?

        // Let's try to answer that question for the base 10 counting system:
        // How many 3 digit numbers in our base 10 counting system?
        // The smallest 3 digit base 10 number is 10^2 = 10^(n-1) = 100
        // The largest 3 digit base 10 number is 10^3 - 1 = 1000 - 1 = 999
        // The inclusive size of this range is 999 - 100 + 1
        // The formula is base^(n-1) - ( base^n - 1 ) + 1 = base^(n-1) - base^n + 2
    }
};

int main() {
    Solution solution;
    int n;

    n = 2;
    cout << solution.countVowelStrings(n) << endl;

    n = 33;
    cout << solution.countVowelStrings(n) << endl;
}
