#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        int ret = 0;

        int i = 0;
        while (i < s.length()) {
            switch (s[i]) {
                case 'I':
                    if (i != s.length() && s[i + 1] == 'V') {
                        ret += 4;
                        ++i;
                    } else if (i != s.length() && s[i + 1] == 'X') {
                        ret += 9;
                        ++i;
                    } else {
                        ++ret;
                    }
                    break;
                case 'V':
                    ret += 5;
                    break;
                case 'X':
                    if (i != s.length() && s[i + 1] == 'L') {
                        ret += 40;
                        ++i;
                    } else if (i != s.length() && s[i + 1] == 'C') {
                        ret += 90;
                        ++i;
                    } else {
                        ret += 10;
                    }
                    break;
                case 'L':
                    ret += 50;
                    break;
                case 'C':
                    if (i != s.length() && s[i + 1] == 'D') {
                        ret += 400;
                        ++i;
                    } else if (i != s.length() && s[i + 1] == 'M') {
                        ret += 900;
                        ++i;
                    } else {
                        ret += 100;
                    }
                    break;
                case 'D':
                    ret += 500;
                    break;
                case 'M':
                    ret += 1000;
                    break;
            }
            ++i;
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

    // 3
    cout << solution.romanToInt("III") << '\n';

    // 58
    cout << solution.romanToInt("LVIII") << '\n';

    // 1994
    cout << solution.romanToInt("MCMXCIV") << '\n';
}
