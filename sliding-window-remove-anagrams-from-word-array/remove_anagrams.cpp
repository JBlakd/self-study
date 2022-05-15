#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> removeAnagrams(vector<string>& words) {
        int end_idx = 1;
        string original = words[end_idx - 1];
        while (end_idx <= words.size() - 1) {
            if (is_anagram(words[end_idx - 1], words[end_idx])) {
                words.erase(words.begin() + end_idx);
            } else {
                ++end_idx;
            }
        }

        return words;
    }

   private:
    bool is_anagram(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
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
    vector<string> words;

    words = {"abba", "baba", "bbaa", "cd", "cd"};
    words = solution.removeAnagrams(words);
    print_vector(words);
    cout << endl;

    words = {"a", "b", "c", "d", "e"};
    words = solution.removeAnagrams(words);
    print_vector(words);
    cout << endl;
}
