#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        // Manacher's Algorithm

        string padded_s(2 * s.length() + 1, '#');

        // Make padded string
        int i = 0;
        for (int padded_i = 0; padded_i < padded_s.length(); ++padded_i) {
            // Only populated padded string odd indices
            if (padded_i % 2 == 1) {
                padded_s[padded_i] = s[i];
                ++i;
            }
        }

        vector<int> half_p_len(padded_s.length(), -1);

        int c = 0;
        while (c < padded_s.length()) {
            // if unvisited
            if (half_p_len[c] == -1) {
                // keep trying to expand
                half_p_len[c] = 0;
                while (c - half_p_len[c] - 1 >= 0 && c + half_p_len[c] + 1 < padded_s.length() && padded_s[c - half_p_len[c] - 1] == padded_s[c + half_p_len[c] + 1]) {
                    ++half_p_len[c];
                }
            }

            bool modified = false;

            // Inner loop for this index's half_p_len
            for (int i = 0; i < half_p_len[c]; ++i) {
                int r_mirror_idx = c + 1 + i;
                int l_mirror_idx = c - 1 - i;

                // three cases
                if (l_mirror_idx - half_p_len[l_mirror_idx] > c - half_p_len[c]) {
                    // within boundary, equal to left mirror
                    half_p_len[r_mirror_idx] = half_p_len[l_mirror_idx];
                } else if (l_mirror_idx - half_p_len[l_mirror_idx] < c - half_p_len[c]) {
                    // beyond boundary, equal to distance to edge
                    half_p_len[r_mirror_idx] = c + half_p_len[c] - r_mirror_idx;
                } else {
                    // equal to boundary, new center
                    c = r_mirror_idx;
                    modified = true;
                    break;
                }
            }

            if (!modified) {
                ++c;
            }
        }

        int max_idx = -1;
        int maximum = -1;
        for (int i = 0; i < half_p_len.size(); ++i) {
            if (half_p_len[i] > maximum) {
                max_idx = i;
                maximum = half_p_len[i];
            }
        }

        string ret = "";
        for (int i = max_idx - maximum; i <= max_idx + maximum; ++i) {
            if (padded_s[i] != '#') {
                ret.push_back(padded_s[i]);
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
    string s;
    string output;

    s = "h";
    output = solution.longestPalindrome(s);
    cout << output << '\n';
    assert((output == "h"));

    s = "abacabacabb";
    output = solution.longestPalindrome(s);
    cout << output << '\n';
    assert((output == "bacabacab"));

    s = "babad";
    output = solution.longestPalindrome(s);
    cout << output << '\n';
    assert((output == "bab") || (output == "aba"));

    s = "cbbd";
    output = solution.longestPalindrome(s);
    cout << output << '\n';
    assert((output == "bb"));

    ifstream ifs("war_and_peace_gutenberg.txt");
    s.assign(istreambuf_iterator<char>{ifs}, {});
    output = solution.longestPalindrome(s);
    cout << output << '\n';
    assert((output == "ton did not"));
    ifs.close();

    ifs.open("What is Autism.txt");
    s.assign(istreambuf_iterator<char>{ifs}, {});
    output = solution.longestPalindrome(s);
    cout << output << '\n';
    ifs.close();
    // assert((output == "ton did not"));

    cout << "Great success!" << '\n';
}
