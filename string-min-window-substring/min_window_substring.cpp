#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }

        unordered_map<char, int> hashmap;
        for (char& c : t) {
            ++hashmap[c];
        }

        int left = 0;
        int right = t.length() - 1;
        for (int i = 0; i <= right; ++i) {
            // only care about characters in the original hashmap
            if (hashmap.find(s[i]) != hashmap.end()) {
                --hashmap[s[i]];
            }
        }

        int ret_left = -1;
        int ret_right = s.length() + 1;

        // creep the window
        while (right < s.length()) {
            if (has_all_letters(hashmap)) {
                if (right - left < ret_right - ret_left) {
                    // if statement TODO
                    ret_left = left;
                    ret_right = right;
                }
                // advance left pointer and update hashmap
                ++left;
                if (hashmap.find(s[left - 1]) != hashmap.end()) {
                    ++hashmap[s[left - 1]];
                }
            } else {
                // advance right pointer
                ++right;
                if (right < s.length() && hashmap.find(s[right]) != hashmap.end()) {
                    --hashmap[s[right]];
                }
            }
        }

        if (ret_left == -1) {
            return "";
        }

        return s.substr(ret_left, ret_right - ret_left + 1);
    }

   private:
    bool has_all_letters(unordered_map<char, int>& hashmap) {
        for (auto& [c, count] : hashmap) {
            if (count > 0) {
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
    string t;
    string output;

    s = "gIGUIUIVJVYUICVyiuhuhGhiGvhiVhuGHUHIguiuioubBJKJCGHctu";
    t = "uVYioh";
    output = solution.minWindow(s, t);
    cout << output << '\n';
    assert(output == "YUICVyiuhuhGhiGvhiVhuGHUHIguiuio");

    s = "ADOBECODEBANC";
    t = "ABC";
    output = solution.minWindow(s, t);
    cout << output << '\n';
    assert(output == "BANC");

    s = "a";
    t = "aa";
    output = solution.minWindow(s, t);
    cout << output << '\n';
    assert(output == "");

    s = "a";
    t = "a";
    output = solution.minWindow(s, t);
    cout << output << '\n';
    assert(output == "a");

    cout << "Great success!" << '\n';
}
