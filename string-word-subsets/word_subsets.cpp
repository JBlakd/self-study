#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<vector<int>> hashmaps_ref(words1.size(), vector<int>(26, 0));
    for (int i = 0; i < words1.size(); ++i) {
      for (char& c : words1[i]) {
        ++hashmaps_ref[i][c - 'a'];
      }
    }

    vector<string> ret;
    vector<vector<int>> hashmaps_mutable(words1.size(), vector<int>(26, 0));
    for (int i = 0; i < words1.size(); ++i) {
      bool is_cur_word_valid = true;

      for (string& word2 : words2) {
        // reset current hashmap
        copy(begin(hashmaps_ref[i]), end(hashmaps_ref[i]), begin(hashmaps_mutable[i]));
        for (char& c : word2) {
          --hashmaps_mutable[i][c - 'a'];
          if (hashmaps_mutable[i][c - 'a'] == -1) {
            is_cur_word_valid = false;
            break;
          }
        }
        if (!is_cur_word_valid) {
          break;
        }
      }

      if (is_cur_word_valid) {
        ret.push_back(words1[i]);
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
  vector<string> words1;
  vector<string> words2;
  vector<string> output;

  words1 = {"leetcode", "google", "amazon", "apple", "facebook"};
  words2 = {"lo", "eo"};
  output = solution.wordSubsets(words1, words2);
  print_vector(output);
  cout << '\n';
  assert((output == vector<string>{"leetcode", "google"}));

  words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
  words2 = {"e", "o"};
  output = solution.wordSubsets(words1, words2);
  print_vector(output);
  cout << '\n';
  assert((output == vector<string>{"facebook", "google", "leetcode"}));

  cout << "Great success!" << '\n';
}
