#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestPalindrome(string s) {
        int hashmap['z' - 'A' + 1] = {0};

        for (char c : s) {
            ++hashmap[c - 'A'];
        }

        int ret = 0;

        // Find the first odd seed
        for (int i = 0; i < 'z' - 'A' + 1; ++i) {
            if (hashmap[i] % 2 != 0) {
                ++ret;
                --hashmap[i];
                break;
            }
        }

        // Build letters around the odd seed
        for (int i = 0; i < 'z' - 'A' + 1; ++i) {
            if (hashmap[i] > 1) {
                if (hashmap[i] % 2 == 0) {
                    ret += hashmap[i];
                    hashmap[i] = 0;
                } else {
                    ret += (hashmap[i] - 1);
                    hashmap[i] = 1;
                }
            }
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
    string s;

    // 9
    s = "abccccddZZZ";
    cout << solution.longestPalindrome(s) << '\n';

    // 7
    s = "abccccdd";
    cout << solution.longestPalindrome(s) << '\n';

    // 1
    s = "y";
    cout << solution.longestPalindrome(s) << '\n';
}
