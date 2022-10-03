#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(string colors, vector<int>& neededTime) {
    int ret = 0;

    for (int i = 0; i < neededTime.size() - 1; ++i) {
      if (colors[i] == colors[i + 1]) {
        if (neededTime[i] < neededTime[i + 1]) {
          ret += neededTime[i];
        } else {
          ret += neededTime[i + 1];
        }
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
