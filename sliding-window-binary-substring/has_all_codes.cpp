#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool hasAllCodes(string s, int k) {
        if (k >= s.length()) {
            return false;
        }

        // Slide the window once, add all encountered into a set
        // count up the binary and return false on first number not in set
        unordered_set<uint32_t> substr_set;

        for (int i = 0; i <= s.length() - k; ++i) {
            substr_set.insert(stoul(s.substr(i, k), nullptr, 2));
        }

        for (uint32_t i = 0; i <= (1 << k) - 1; ++i) {
            if (substr_set.find(i) == substr_set.end()) {
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
    string s;
    int k;

    // 0
    s = "0";
    k = 20;
    cout << solution.hasAllCodes(s, k) << endl;

    // 1
    s = "00110110";
    k = 2;
    cout << solution.hasAllCodes(s, k) << endl;

    // 1
    s = "0110";
    k = 1;
    cout << solution.hasAllCodes(s, k) << endl;

    // 0
    s = "0110";
    k = 2;
    cout << solution.hasAllCodes(s, k) << endl;
}
