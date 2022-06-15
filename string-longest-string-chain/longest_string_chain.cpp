#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        if (words.size() == 1) {
            return 1;
        }

        // sort, remove one letter at a time and compare with set, memoize with hashmap
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.length() > b.length();
        });

        // A map for keeping track of maximum chain length ending at this word
        // also for constant time word validity lookup
        unordered_map<string, int> score;
        for (string& word : words) {
            score.emplace(word, 1);
        }

        // Loop through each word
        for (string& word : words) {
            // For each word, remove a letter
            string processed(word.length() - 1, '$');
            int processed_idx = 0;
            for (int i = 0; i < word.length(); i++) {
                // Remove the letter at index i
                for (int j = 0; j < word.length(); j++) {
                    if (i == j) {
                        continue;
                    }
                    processed[processed_idx] = word[j];
                    ++processed_idx;
                }

                // if the result is valid, increase the result's score
                if (score.find(processed) != score.end()) {
                    score[processed] = max(score[processed], score[word] + 1);
                }
                processed_idx = 0;
            }
        }

        // return maximum score
        int ret = 0;
        for (auto& [word, chain_length] : score) {
            ret = max(ret, chain_length);
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
    vector<string> words;
    int output;

    words = {"abc", "a", "ab", "abdd", "ac", "bd", "abd"};
    output = solution.longestStrChain(words);
    cout << output << '\n';
    assert((output == 4));

    words = {"a", "b", "ba", "bca", "bda", "bdca"};
    output = solution.longestStrChain(words);
    cout << output << '\n';
    assert((output == 4));

    words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    output = solution.longestStrChain(words);
    cout << output << '\n';
    assert((output == 5));

    words = {"abcd", "dbqca"};
    output = solution.longestStrChain(words);
    cout << output << '\n';
    assert((output == 1));

    cout << "Great success!" << '\n';
}
