#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool reorderedPowerOf2(int n) {
    // contains digit counts of 2e0 to 2e29
    int hashmaps[30][10] = {0};
    // initial 2 to the power of 0
    int power = 1;
    // initial digit count of 2e0
    hashmaps[0][1] = 1;
    for (int i = 1; i < 30; ++i) {
      power *= 2;
      string power_str = to_string(power);
      for (char& c : power_str) {
        ++hashmaps[i][c - '0'];
      }
    }

    string input_str = to_string(n);
    int input_hashmap[10] = {0};
    for (char& c : input_str) {
      ++input_hashmap[c - '0'];
    }

    // compare input hashmap to all possible powers of two hashmaps
    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (hashmaps[i][j] != input_hashmap[j]) {
          break;
        }

        // a winner is you
        if (j == 9) {
          return true;
        }
      }
    }

    return false;
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

  assert(solution.reorderedPowerOf2(1) == true);

  cout << "Great success!" << '\n';
}
