#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ret;
    if (p.length() > s.length()) {
      return ret;
    }

    // frequency of every lower case letter in the p string
    uint16_t freq_table[26] = {0};
    for (uint32_t i = 0; i < p.length(); ++i) {
      ++freq_table[to_idx(p.at(i))];
    }

    // Sliding window initialisation
    uint16_t slide_start = 0;
    uint16_t slide_end = p.length() - 1;
    uint16_t freq_copy[26] = {0};
    for (uint16_t i = slide_start; i <= slide_end; ++i) {
      ++freq_copy[to_idx(s.at(i))];
    }

    // while loop for sliding window
    while (slide_end < s.length()) {
      // loop through sliding window
      if (is_equal(freq_table, freq_copy, 26)) {
        ret.push_back(slide_start);
      }

      ++slide_start;
      ++slide_end;

      --freq_copy[to_idx(s.at(slide_start - 1))];
      if (slide_end < s.length()) {
        ++freq_copy[to_idx(s.at(slide_end))];
      }
    }

    return ret;
  }

 private:
  int to_idx(char c) {
    return (int)c - 97;
  }

  char to_char(int idx) {
    return (char)(idx + 97);
  }

  bool is_equal(uint16_t* arr, uint16_t* arr2, uint16_t len) {
    for (uint16_t i = 0; i < len; i++) {
      if (arr[i] != arr2[i]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution solution;
  vector<int> results;

  results = solution.findAnagrams("cbaebabacd", "abc");
  for (auto result : results) {
    cout << result << ", ";
  }
  cout << endl;

  results = solution.findAnagrams("abab", "ab");
  for (auto result : results) {
    cout << result << ", ";
  }
  cout << endl;
}
