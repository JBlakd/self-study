#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDeletions(string s) {
        unordered_map<char, int> hashmap;
        for (char& c : s) {
            ++hashmap[c];
        }

        vector<int> sorted;
        for (auto& [c, f] : hashmap) {
            sorted.emplace_back(f);
        }
        sort(sorted.begin(), sorted.end());

        int num_deletes = 0;
        unordered_set<int> seen;
        for (int& freq : sorted) {
            while (seen.find(freq) != seen.end() && freq > 0) {
                --freq;
                ++num_deletes;
            }

            if (freq > 0) {
                seen.emplace(freq);
            }
        }

        return num_deletes;
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
    int output;

    s = "b";
    output = solution.minDeletions(s);
    cout << output << '\n';
    assert(output == 0);

    s = "aab";
    output = solution.minDeletions(s);
    cout << output << '\n';
    assert(output == 0);

    s = "aaabbbcc";
    output = solution.minDeletions(s);
    cout << output << '\n';
    assert(output == 2);

    s = "ceabaacb";
    output = solution.minDeletions(s);
    cout << output << '\n';
    assert(output == 2);

    cout << "Great success!" << '\n';
}
