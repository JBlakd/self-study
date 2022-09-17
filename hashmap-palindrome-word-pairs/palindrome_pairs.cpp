#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ret;

    unordered_map<string, int> hashmap;
    for (int i = 0; i < words.size(); ++i) {
      // empty string edge case
      if (words[i].empty()) {
        for (int j = 0; j < words.size(); ++j) {
          if (i == j) {
            continue;
          }
          if (is_palindrome(words[j], 0, words[j].size() - 1)) {
            ret.push_back({i, j});
            ret.push_back({j, i});
          }
        }
        continue;
      }

      hashmap.emplace(words[i], i);
    }

    for (int i = 0; i < words.size(); ++i) {
      // empty string edge case
      if (words[i].empty()) {
        continue;
      }

      reverse(words[i].begin(), words[i].end());

      // check front partitions of reversed word
      for (int j = 0; j < words[i].size(); ++j) {
        // check existence of front partition in hashmap
        if (j >= 1 && is_palindrome(words[i], j, words[i].size() - 1)) {
          string front_partition = words[i].substr(0, j);
          unordered_map<string, int>::iterator it = hashmap.find(front_partition);
          if (it != hashmap.end() && it->second != i) {
            ret.push_back({it->second, i});
          }
        }

        // if front partition is palindrome, look up back partition in the hashmap
        if (j == 0 || is_palindrome(words[i], 0, j - 1)) {
          string back_partition = words[i].substr(j);
          unordered_map<string, int>::iterator it = hashmap.find(back_partition);
          if (it != hashmap.end() && it->second != i) {
            ret.push_back({i, it->second});
          }
        }
      }
    }

    return ret;
  }

 private:
  bool is_palindrome(string& str, int lo, int hi) {
    while (lo < hi) {
      if (str[lo] != str[hi]) {
        return false;
      }
      ++lo;
      --hi;
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
  vector<vector<int>> output;

  words = {"a", "abc", "aba", ""};
  output = solution.palindromePairs(words);
  for (auto& row : output) {
    print_vector(row);
    cout << ', ';
  }
  cout << '\n';

  words = {"abcd", "dcba", "lls", "s", "sssll"};
  output = solution.palindromePairs(words);
  for (auto& row : output) {
    print_vector(row);
    cout << ', ';
  }
  cout << '\n';

  cout << "Great success!" << '\n';
}
