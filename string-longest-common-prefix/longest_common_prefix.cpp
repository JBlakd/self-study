#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string ret = "";

        while (true) {
            char cur_char = '$';
            // check char at current index
            for (int j = 0; j < strs.size(); ++j) {
                string& str = strs[j];

                if (i == str.length()) {
                    return ret;
                }

                if (cur_char == '$') {
                    cur_char = str[i];
                } else if (str[i] != cur_char) {
                    return ret;
                }

                if (j == strs.size() - 1) {
                    ret.push_back(cur_char);
                }
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
    vector<string> strs;

    // fl
    strs = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs) << '\n';

    //
    strs = {"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs) << '\n';
}
