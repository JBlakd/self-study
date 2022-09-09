#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    // all possible ATK buckets (from 1 to 100000)
    vector<int> atk_buckets(100001, 0);

    // iterate through all players, and record the highest DEF for each ATK bucket
    for (vector<int>& p : properties) {
      atk_buckets[p[0]] = max(p[1], atk_buckets[p[0]]);
    }

    // greedily populate ATK buckets which don't have a distinct point defined for it
    for (int atk = 99999; atk > 0; --atk) {
      atk_buckets[atk] = max(atk_buckets[atk], atk_buckets[atk + 1]);
    }

    // iterate through all points and determine whether it's weak using atk_buckets
    int ret = 0;
    for (vector<int>& p : properties) {
      if (p[0] < 100000 && atk_buckets[p[0] + 1] > p[1]) {
        ++ret;
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
