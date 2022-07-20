#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    // construct indices map
    vector<int> hashmap[26];
    for (int i = 0; i < t.length(); ++i) {
      hashmap[t[i] - 'a'].push_back(i);
    }

    int t_index = -1;
    for (char& c : s) {
      vector<int>& vec = hashmap[c - 'a'];
      vector<int>::iterator it = upper_bound(vec.begin(), vec.end(), t_index);
      if (it == vec.end()) {
        return false;
      }
      t_index = *(it);
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
