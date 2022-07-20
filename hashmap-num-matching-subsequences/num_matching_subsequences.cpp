#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    // construct indices map
    vector<int> hashmap[26];
    for (int i = 0; i < s.length(); ++i) {
      hashmap[s[i] - 'a'].push_back(i);
    }

    int ret = 0;
    for (string& word : words) {
      if (is_subsequence(word, hashmap)) {
        ++ret;
      }
    }

    return ret;
  }

 private:
  bool is_subsequence(string& word, vector<int>* hashmap) {
    int s_index = -1;
    for (char& c : word) {
      vector<int>& vec = hashmap[c - 'a'];
      vector<int>::iterator it = upper_bound(vec.begin(), vec.end(), s_index);
      if (it == vec.end()) {
        return false;
      }
      s_index = *(it);
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
