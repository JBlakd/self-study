#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;

        for (auto& str : strs) {
            // count letter frequency for each string
            // ASCII 'a' is 97
            int freq[26] = {0};
            for (char c : str) {
                ++freq[c - 97];
            }
            // calculate hashkey for each string
            ostringstream oss;
            for (int i = 0; i < 26; ++i) {
                oss << freq[i] << ',';
            }
            string hashkey = oss.str();

            // Put the string in hashmap
            if (hashmap.find(hashkey) == hashmap.end()) {
                // Modern c++ initializer list (even though the list only contains one element)
                hashmap.emplace(hashkey, vector<string>{str});
            } else {
                hashmap.at(hashkey).emplace_back(str);
            }
        }

        vector<vector<string>> ret;
        for (auto& [key, group] : hashmap) {
            ret.emplace_back(vector<string>{});
            for (string& str : group) {
                ret.back().emplace_back(str);
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
    vector<string> strs;

    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (auto& group : solution.groupAnagrams(strs)) {
        print_vector(group);
        cout << ", ";
    }
    cout << endl;

    strs = {"a"};
    for (auto& group : solution.groupAnagrams(strs)) {
        print_vector(group);
        cout << ", ";
    }
    cout << endl;

    strs = {""};
    for (auto& group : solution.groupAnagrams(strs)) {
        print_vector(group);
        cout << ", ";
    }
    cout << endl;
}
