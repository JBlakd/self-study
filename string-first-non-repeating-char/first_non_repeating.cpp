#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int firstUniqChar(string s) {
        vector<int> char_count(26, 0);

        // 'a' is 97
        for (char c : s) {
            ++char_count[c - 97];
        }

        for (int i = 0; i < s.length(); ++i) {
            if (char_count[s[i] - 97] == 1) {
                return i;
            }
        }

        return -1;
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
}
