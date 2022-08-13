#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int window_length = 0;
    int all_words_hashmap[26] = {0};
    for (string& word : words) {
      for (char& c : word) {
        ++all_words_hashmap[c - 'a'];
      }
      window_length += word.length();
    }

    if (window_length > s.length()) {
      return {};
    }

    int cur_window_hashmap[26] = {0};
    for (int i = 0; i < window_length; ++i) {
      ++cur_window_hashmap[s[i] - 'a'];
    }

    vector<int> ret;

    // slide the window
    for (int i = 0; i + window_length <= s.length(); ++i) {
      if (is_hashmaps_match(all_words_hashmap, cur_window_hashmap)) {
        // Check if the window is a valid concatenation of all words
        unordered_map<string_view, int> hashmap;
        for (string& word : words) {
          ++hashmap[word];
        }

        // Check the window word-by-word
        string_view s_view(s);
        bool is_valid_window = true;
        for (int j = i; j + words[0].length() <= i + window_length; j += words[0].length()) {
          string_view substr_view = s_view.substr(j, words[0].length());
          if (hashmap.find(substr_view) != hashmap.end()) {
            if (hashmap[substr_view] > 1) {
              --hashmap[substr_view];
            } else {
              hashmap.erase(substr_view);
            }
          } else {
            // Not a valid window
            is_valid_window = false;
            break;
          }
        }

        if (is_valid_window) {
          ret.push_back(i);
        }
      }

      // update cur_window_hashmap
      if (i + window_length < s.length()) {
        --cur_window_hashmap[s[i] - 'a'];
        ++cur_window_hashmap[s[i + window_length] - 'a'];
      }
    }

    return ret;
  }

 private:
  bool is_hashmaps_match(int* h1, int* h2) {
    for (int i = 0; i < 26; ++i) {
      if (h1[i] != h2[i]) {
        return false;
      }
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
  string s;
  vector<string> words;
  vector<int> output;

  s = "abababab";
  words = {"ab", "ba"};
  output = solution.findSubstring(s, words);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{}));

  s = "wordgoodgoodgoodbestword";
  words = {"word", "good", "best", "good"};
  output = solution.findSubstring(s, words);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{8}));

  s = "q";
  words = {"q"};
  output = solution.findSubstring(s, words);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{0}));

  s = "barfoothefoobarman";
  words = {"foo", "bar"};
  output = solution.findSubstring(s, words);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{0, 9}));

  s = "wordgoodgoodgoodbestword";
  words = {"word", "good", "best", "word"};
  output = solution.findSubstring(s, words);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{}));

  s = "barfoofoobarthefoobarman";
  words = {"bar", "foo", "the"};
  output = solution.findSubstring(s, words);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{6, 9, 12}));

  cout << "Great success!" << '\n';
}
