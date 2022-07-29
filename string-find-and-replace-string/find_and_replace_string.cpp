#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ret;
    vector<int> ref_pattern_vec(pattern.length());

    // calculate reference pattern
    calc_pattern_vec(pattern, ref_pattern_vec);

    vector<int> cur_pattern_vec(pattern.length());
    for (string& word : words) {
      calc_pattern_vec(word, cur_pattern_vec);
      if (cur_pattern_vec == ref_pattern_vec) {
        ret.push_back(word);
      }
    }

    return ret;
  }

 private:
  void calc_pattern_vec(string& pattern, vector<int>& pattern_vec) {
    int cur_int = 1;
    int hashmap[26] = {0};
    for (int i = 0; i < pattern.length(); ++i) {
      char& c = pattern[i];
      if (hashmap[c - 'a'] == 0) {
        hashmap[c - 'a'] = cur_int;
        ++cur_int;
      }
      pattern_vec[i] = hashmap[c - 'a'];
    }
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
  string pattern;
  vector<string> output;

  words = {"abcb", "khjy", "fwnw"};
  pattern = "zlol";
  output = solution.findAndReplacePattern(words, pattern);
  print_vector(output);
  cout << '\n';
  assert((output == vector<string>{"abcb", "fwnw"}));

  words = {"a"};
  pattern = "z";
  output = solution.findAndReplacePattern(words, pattern);
  print_vector(output);
  cout << '\n';
  assert((output == vector<string>{"a"}));

  words = {"ab", "jj"};
  pattern = "zy";
  output = solution.findAndReplacePattern(words, pattern);
  print_vector(output);
  cout << '\n';
  assert((output == vector<string>{"ab"}));

  cout << "Great success!" << '\n';
}
