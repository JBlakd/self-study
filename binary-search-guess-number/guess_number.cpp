#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mystery_number;

int guess(int n) {
    if (n < mystery_number) {
        // guessed too low
        return 1;
    } else if (n > mystery_number) {
        // guessed too high
        return -1;
    } else {
        return 0;
    }
}

class Solution {
   public:
    int guessNumber(int n) {
        unsigned int max = n;
        unsigned int min = 1;
        int guess_num;
        int guess_result;
        while (true) {
            guess_num = (int)((max + min) / 2);
            // cout << "guess_num: " << guess_num << endl;
            guess_result = guess(guess_num);
            if (guess_result == 0) {
                return guess_num;
            }

            if (guess_result == 1) {
                // guessed too low
                min = guess_num + 1;
            } else {
                // guessed too high
                max = guess_num - 1;
            }
        }

        return -1;
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
    int n;

    n = 9;
    mystery_number = 1;
    cout << solution.guessNumber(n) << endl;

    n = 9;
    mystery_number = 2;
    cout << solution.guessNumber(n) << endl;

    n = 9;
    mystery_number = 3;
    cout << solution.guessNumber(n) << endl;

    n = 9;
    mystery_number = 4;
    cout << solution.guessNumber(n) << endl;

    n = 9;
    mystery_number = 5;
    cout << solution.guessNumber(n) << endl;

    n = 9;
    mystery_number = 6;
    cout << solution.guessNumber(n) << endl;

    n = 9;
    mystery_number = 7;
    cout << solution.guessNumber(n) << endl;

    n = 9;
    mystery_number = 8;
    cout << solution.guessNumber(n) << endl;

    n = 9;
    mystery_number = 9;
    cout << solution.guessNumber(n) << endl;

    n = 2147483647;
    mystery_number = 2147483646;
    cout << solution.guessNumber(n) << endl;
}
