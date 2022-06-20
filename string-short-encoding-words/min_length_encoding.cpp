#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        // preprocess words: remove duplicates
        unordered_set<string> unique;
        for (auto& word : words) {
            unique.emplace(word);
        }
        words = vector<string>(unique.begin(), unique.end());

        // -1 denotes consumed, -2 denotes invalid (but will be in the encoded string)
        // any other value denotes this word consumd other words and will be in the encoded string
        vector<int> idx_vec(words.size());

        int exists[26] = {0};

        for (int i = 0; i < words.size(); ++i) {
            idx_vec[i] = words[i].length() - 1;
        }

        // each iteration of this loop deals with one letter of every word
        while (true) {
            bool finished = true;
            // count one letters from every word, and increment its count
            for (int i = 0; i < words.size(); ++i) {
                if (idx_vec[i] < 0) {
                    // disregard words which have been completed or invalidated
                    continue;
                }
                finished = false;
                ++exists[words[i][idx_vec[i]] - 'a'];
            }

            if (finished) {
                break;
            }

            // for each word, invalidate if its current letter isn't shared by any other
            for (int i = 0; i < words.size(); ++i) {
                if (idx_vec[i] < 0) {
                    // disregard words which have been completed or invalidated
                    continue;
                }
                if (exists[words[i][idx_vec[i]] - 'a'] == 1) {
                    idx_vec[i] = -2;
                }
            }

            // for each word, move onto the next letter
            for (int i = 0; i < words.size(); ++i) {
                if (idx_vec[i] < 0) {
                    // disregard words which have been completed or invalidated
                    continue;
                }
                // we're about to leave this letter behind, so decrement its count
                --exists[words[i][idx_vec[i]] - 'a'];
                --idx_vec[i];
            }
        }

        int ret = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (idx_vec[i] == -2 || idx_vec[i] >= 0) {
                ret += words[i].length() + 1;
            }
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

    // climb#
    words = {"climb", "limb", "climb", "climb"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 6);

    // time#
    words = {"time", "time", "time", "time"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // climb#
    words = {"climb", "limb"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 6);

    // time#
    words = {"time"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // qwosp#grahp# 12
    words = {"p", "grahp", "qwosp"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 12);

    // chime#bell# 11
    words = {"chime", "ime", "me", "bell"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 11);

    // time# 5
    words = {"me", "time", "ime"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // time# 5
    words = {"time", "me"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // time# 5
    words = {"me", "time"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // chime#time#bell# 16
    words = {"chime", "time", "me", "bell"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 16);

    // t# 2
    words = {"t"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 2);

    cout << "Great success!" << '\n';
}
