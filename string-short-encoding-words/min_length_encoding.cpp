#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        if (words.size() == 1) {
            return words[0].length() + 1;
        }

        int active_word_idx = 0;
        string encoded = "";
        if (words[1].length() > words[0].length()) {
            active_word_idx = 1;
        }
        encoded.append(words[active_word_idx]);
        encoded.push_back('#');

        for (int i = 0; i < words.size(); ++i) {
            if (active_word_idx == i) {
                continue;
            }
            string::reverse_iterator active_word_it = words[active_word_idx].rbegin();
            string::reverse_iterator cur_word_it = words[i].rbegin();
            while (cur_word_it < words[i].rend() && active_word_it < words[active_word_idx].rend()) {
                if (*active_word_it == *cur_word_it) {
                    ++cur_word_it;
                    ++active_word_it;
                } else {
                    break;
                }
            }

            // no words reached the end
            if (cur_word_it != words[i].rend() && active_word_it != words[active_word_idx].rend()) {
                // passing of the torch
                active_word_idx = i;
                encoded.append(words[active_word_idx]);
                encoded.push_back('#');
                continue;
            }

            // also pass the torch if the current active word has been exhausted
            if (active_word_it == words[active_word_idx].rend()) {
                active_word_idx = i;
                encoded.append(words[active_word_idx]);
                encoded.push_back('#');
            }
        }

        // cout << encoded << ' ';

        return encoded.length();
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

    // qwosp#grah# 11
    words = {"p", "grah", "qwosp"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 11);

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
