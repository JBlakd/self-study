#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        // Don't actually have to implement a trie for this,
        // but a trie was used to visualise the problem and to formulate a solution

        // Key: a string consisting of the first character of the word, then the last character of the word, then length of the word
        // Value: a vector of indices of the input vector representing all the words which fit the key criteria
        unordered_map<string, unordered_set<int>> hashmap;
        // Keys array so we don't have to recalculate the key
        vector<string> keys(words.size());

        for (int i = 0; i < words.size(); ++i) {
            string key(2, '$');
            key[0] = words[i][0];
            key[1] = words[i].back();
            key.append(to_string(words[i].length()));
            hashmap[key].emplace(i);
            keys[i] = key;
        }

        // unordered_set<string> exists;
        vector<string> ret(words.size(), "");

        // calculating each result of the return vector
        for (int i = 0; i < words.size(); ++i) {
            // already calculated
            if (ret[i].length() > 0) {
                continue;
            }

            // If no conflicts and the potential abbreviation actually abbreviates
            if (hashmap[keys[i]].size() == 1 && words[i].length() > 3) {
                ret[i].push_back(words[i][0]);
                ret[i].append(to_string(words[i].length() - 2));
                ret[i].push_back(words[i].back());
                continue;
            }

            if (words[i].length() <= 3) {
                ret[i] = words[i];
                continue;
            }

            // copy, because it needs to be removed
            unordered_set<int> same_key_words = hashmap[keys[i]];
            int j;
            for (j = 0; j < words[i].length(); ++j) {
                // find divergence by selective removal
                // TODO: don't use range-based for loop
            }

            // Currently at first unique character
            if (words[i].length() - j < 3) {
                // if abbreviation is not useful, move on to the next word
                break;
            }

            string abbreviation(words[i].begin(), words[i].begin() + j + 1);
            abbreviation.append(to_string(words[i].length() - j - 2));
            abbreviation.push_back(words[i].back());
            ret[i] = abbreviation;
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
    vector<string> expected;
    vector<string> output;

    words = {"intuits", "intercoms", "internets"};
    output = solution.wordsAbbreviation(words);
    print_vector(output);
    cout << '\n';
    expected = {"i5s", "interc2s", "intern2s"};
    for (int i = 0; i < output.size(); ++i) {
        assert(output[i] == expected[i]);
    }

    words = {"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
    output = solution.wordsAbbreviation(words);
    print_vector(output);
    cout << '\n';
    expected = {"l2e", "god", "internal", "me", "i6t", "interval", "inte4n", "f2e", "intr4n"};
    for (int i = 0; i < output.size(); ++i) {
        assert(output[i] == expected[i]);
    }

    cout << "Great success!" << '\n';
}
