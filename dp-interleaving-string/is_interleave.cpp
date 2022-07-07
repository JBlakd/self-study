#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (abs((int)s1.length() - (int)s2.length()) > 1) {
            return false;
        }

        int s1_i = 0;
        int s2_i = 0;

        for (char& c : s3) {
            if (s1_i < s1.length() && c == s1[s1_i]) {
                ++s1_i;
            } else if (s2_i < s2.length() && c == s2[s2_i]) {
                ++s2_i;
            } else {
                return false;
            }
        }

        return true;
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
    string s1;
    string s2;
    string s3;
    bool output;

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbbaccc";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == false);

    s1 = "";
    s2 = "";
    s3 = "";
    output = solution.isInterleave(s1, s2, s3);
    cout << (output ? "true\n" : "false\n");
    assert(output == true);

    cout << "Great success!" << '\n';
}
