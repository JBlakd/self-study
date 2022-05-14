// leetcode 5299

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int divisorSubstrings(int num, int k) {
        string num_str = to_string(num);
        int left_idx = 0;
        int right_idx = k - 1;

        int ret = 0;
        while (right_idx < num_str.length()) {
            string sub_str = num_str.substr(left_idx, k);
            int sub_int = stoi(sub_str, nullptr, 10);

            // check sub_int validity
            if (sub_int != 0) {
                // check sub_int eligibility to score points
                if (num % sub_int == 0) {
                    ++ret;
                }
            }

            ++left_idx;
            ++right_idx;
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
    int num;
    int k;

    num = 999999999;
    k = 2;
    cout << solution.divisorSubstrings(num, k) << endl;

    num = 1000000000;
    k = 1;
    cout << solution.divisorSubstrings(num, k) << endl;

    num = 9;
    k = 1;
    cout << solution.divisorSubstrings(num, k) << endl;

    num = 240;
    k = 2;
    cout << solution.divisorSubstrings(num, k) << endl;

    num = 430043;
    k = 2;
    cout << solution.divisorSubstrings(num, k) << endl;
}
