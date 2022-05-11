#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countVowelStrings(int n) {
        char vowels[] = "aeiou";
        string cur_string = "";
        int ret = 0;
        dfs(vowels, 0, cur_string, ret, n);
        return ret;
    }

   private:
    void dfs(const char* vowels, int cur_vowel_idx, string& cur_string, int& ret, const int& n) {
        // cout << "Exploring: " << cur_string;

        // success base case
        if (cur_string.length() == n) {
            ++ret;
            // cout << " (found!)" << endl;
            return;
        }

        // cout << endl;

        for (int i = cur_vowel_idx; i < 5; ++i) {
            cur_string.append(1, vowels[i]);
            dfs(vowels, i, cur_string, ret, n);
            // backtrack
            cur_string.pop_back();
        }
    }
};

int main() {
    Solution solution;
    int n;

    n = 2;
    cout << solution.countVowelStrings(n) << endl;

    n = 33;
    cout << solution.countVowelStrings(n) << endl;
}
