#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    // Reduce all words in words2 to single word
    vector<int> words2_master_ref(26, 0);
    for (string& word2 : words2) {
      vector<int> cur_word2_hashmap(26, 0);
      // populate current word's hashmap
      for (char& c : word2) {
        ++cur_word2_hashmap[c - 'a'];
      }

      // populate the master hashmap
      for (int i = 0; i < 26; ++i) {
        words2_master_ref[i] = max(words2_master_ref[i], cur_word2_hashmap[i]);
      }
    }

    vector<string> ret;
    for (string& word1 : words1) {
      bool is_valid = true;
      vector<int> words2_master_copy(words2_master_ref);

      // create cur word1's hashmap
      vector<int> words1_cur_ref(26, 0);
      for (char& c : word1) {
        ++words1_cur_ref[c - 'a'];
      }

      // checking
      for (int i = 0; i < 26; ++i) {
        words1_cur_ref[i] -= words2_master_copy[i];
        if (words1_cur_ref[i] < 0) {
          is_valid = false;
          break;
        }
      }

      if (is_valid) {
        ret.push_back(word1);
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
