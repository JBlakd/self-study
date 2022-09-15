#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findOriginalArray(vector<int>& changed) {
    if (changed.size() % 2 != 0) {
      return {};
    }

    sort(changed.begin(), changed.end());

    unordered_multiset<int> hashset;

    for (int& num : changed) {
      hashset.emplace(num);
    }

    // get rid of all zeroes
    vector<int> ret;
    int zeroes_erased = hashset.erase(0);
    if (zeroes_erased % 2 != 0) {
      return {};
    } else {
      ret.insert(ret.end(), zeroes_erased / 2, 0);
    }

    for (int& num : changed) {
      unordered_multiset<int>::iterator num_it = hashset.find(num);
      if (num_it == hashset.end()) {
        continue;
      }

      unordered_multiset<int>::iterator num_doubled_it = hashset.find(num * 2);
      if (num_doubled_it == hashset.end()) {
        return {};
      }

      ret.emplace_back(*(num_it));
      hashset.erase(num_it);
      hashset.erase(num_doubled_it);
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
