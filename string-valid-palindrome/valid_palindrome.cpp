#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPalindrome(string s) {
        if (s.length() == 1) {
            return true;
        }

        int lo = 0;
        if (!is_valid_char(s.at(lo))) {
            get_next(lo, s);
        }

        int hi = s.length() - 1;
        if (!is_valid_char(s.at(hi))) {
            get_prev(hi, s);
        }

        if (lo > hi) {
            return true;
        }

        while (lo < hi) {
            if (tolower(s.at(lo)) != tolower(s.at(hi))) {
                return false;
            }
            get_next(lo, s);
            get_prev(hi, s);
        }

        return true;
    }

   private:
    bool is_valid_char(char c) {
        return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57));
    }

    void get_next(int& i, string& s) {
        do {
            if (i == s.length() - 1) {
                return;
            }
            ++i;
        } while (!is_valid_char(s.at(i)));
    }

    void get_prev(int& i, string& s) {
        do {
            if (i == 0) {
                return;
            }
            --i;
        } while (!is_valid_char(s.at(i)));
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

    // 0
    s = ".,";
    cout << solution.isPalindrome(s) << endl;

    // 1
    s = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(s) << endl;

    // 0
    s = "race a car";
    cout << solution.isPalindrome(s) << endl;
}
