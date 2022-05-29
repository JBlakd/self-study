#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        // Sort words by descending length
        sort(words.begin(), words.end(), [](string& first, string& second) { return first.size() > second.size(); });

        int ret = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i; j < words.size(); ++j) {
                if (words[i].length() * words[j].length() <= ret) {
                    continue;
                }

                if (no_common_letters(words[i], words[j])) {
                    ret = max(ret, (int)words[i].length() * (int)words[j].length());
                }
            }
        }

        return ret;
    }

   private:
    bool no_common_letters(string& s1, string& s2) {
        // ascii 'a' is 97

        uint32_t s1_bits = 0;
        for (char c : s1) {
            s1_bits |= (1 << (c - 97));
        }
        uint32_t s2_bits = 0;
        for (char c : s2) {
            s2_bits |= (1 << (c - 97));
        }

        // if s1_bits AND s2_bits is not zero, it means they share common letters
        return !(s1_bits & s2_bits);
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
    vector<string> words;

    // 16
    words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << solution.maxProduct(words) << endl;

    // 4
    words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    cout << solution.maxProduct(words) << endl;

    // 0
    words = {"a", "aa", "aaa", "aaaa"};
    cout << solution.maxProduct(words) << endl;
}
