#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        string* shorter = (a.length() < b.length()) ? &a : &b;
        string* longer = (shorter == &a) ? &b : &a;

        string ret(longer->length() + 1, '.');

        int long_idx = longer->length() - 1;
        int short_idx = shorter->length() - 1;
        int ret_idx = ret.length() - 1;

        bool carry = false;
        while (long_idx >= 0) {
            if (short_idx < 0 || shorter->at(short_idx) == '0') {
                if (longer->at(long_idx) == '1') {
                    if (carry) {
                        ret[ret_idx] = '0';
                        carry = true;
                    } else {
                        ret[ret_idx] = '1';
                        carry = false;
                    }
                } else {
                    if (carry) {
                        ret[ret_idx] = '1';
                        carry = false;
                    } else {
                        ret[ret_idx] = '0';
                        carry = false;
                    }
                }
            } else {
                if (longer->at(long_idx) == '1') {
                    if (carry) {
                        ret[ret_idx] = '1';
                        carry = true;
                    } else {
                        ret[ret_idx] = '0';
                        carry = true;
                    }
                } else {
                    if (carry) {
                        ret[ret_idx] = '0';
                        carry = true;
                    } else {
                        ret[ret_idx] = '1';
                        carry = false;
                    }
                }
            }

            --long_idx;
            --short_idx;
            --ret_idx;
        }

        if (carry) {
            ret[ret_idx] = '1';
            return ret;
        } else {
            return string(ret.begin() + 1, ret.end());
        }
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
    string a;
    string b;

    // 10101
    a = "1010";
    b = "1011";
    cout << solution.addBinary(a, b) << '\n';

    // 100
    a = "11";
    b = "1";
    cout << solution.addBinary(a, b) << '\n';
}
