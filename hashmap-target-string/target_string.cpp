#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int rearrangeCharacters(string s, string target) {
        // ASCII 'a' is 97
        vector<int> freq(26, 0);
        for (char c : s) {
            ++freq[c - 97];
        }

        vector<int> targetfreq(26, 0);
        for (char c : target) {
            ++targetfreq[c - 97];
        }

        int ret = numeric_limits<int>::max();
        for (char c : target) {
            if (targetfreq[c - 97] == 0) {
                continue;
            }
            // "withdraw"
            ret = min(ret, freq[c - 97] / targetfreq[c - 97]);
            targetfreq[c - 97] = 0;
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
    string target;

    // 1
    s = "abbaccaddaeea";
    target = "aaaaa";
    cout << solution.rearrangeCharacters(s, target) << endl;

    // 2
    s = "ilovecodingonleetcode";
    target = "code";
    cout << solution.rearrangeCharacters(s, target) << endl;

    // 1
    s = "abcba";
    target = "abc";
    cout << solution.rearrangeCharacters(s, target) << endl;
}
