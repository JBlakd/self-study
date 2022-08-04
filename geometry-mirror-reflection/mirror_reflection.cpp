#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int mirrorReflection(int p, int q) {
    // due to the testcases, the equation m*p = n*q is always true for some values of m and n
    // Just have to find it

    // Start with values which guarantee the equation
    int m = q;
    int n = p;

    // find the lowest common factor
    while (m % 2 == 0 && n % 2 == 0) {
      m /= 2;
      n /= 2;
    }

    if (n % 2 == 0) {
      // left wall
      return 2;
    }
    // else right wall
    if (m % 2 == 0) {
      // beam is going down
      return 0;
    }

    return 1;
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
