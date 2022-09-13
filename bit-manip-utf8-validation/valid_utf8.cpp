#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validUtf8(vector<int>& data) {
    int i = 0;
    while (i < data.size()) {
      if (!(data[i] & (1 << 7))) {
        // 1 byte, do nothing
      } else if (data[i] & (1 << 6) && !(data[i] & (1 << 5))) {
        // 2 byte
        if (i >= (int)data.size() - 1) {
          return false;
        }

        ++i;
        if (!(data[i] & (1 << 7) && !(data[i] & (1 << 6)))) {
          return false;
        }
      } else if (data[i] & (1 << 6) && data[i] & (1 << 5) && !(data[i] & (1 << 4))) {
        // 3 byte
        if (i >= (int)data.size() - 2) {
          return false;
        }

        for (int j = 0; j < 2; ++j) {
          ++i;
          if (!(data[i] & (1 << 7) && !(data[i] & (1 << 6)))) {
            return false;
          }
        }
      } else if (data[i] & (1 << 6) && data[i] & (1 << 5) && data[i] & (1 << 4) && !(data[i] & (1 << 3))) {
        // 4 byte
        if (i >= (int)data.size() - 3) {
          return false;
        }

        for (int j = 0; j < 3; ++j) {
          ++i;
          if (!(data[i] & (1 << 7) && !(data[i] & (1 << 6)))) {
            return false;
          }
        }
      } else {
        // invalid pattern found
        return false;
      }

      ++i;
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
  vector<int> data;
  bool output;

  data = {237};
  output = solution.validUtf8(data);
  assert((output == false));

  cout << "Great success!" << '\n';
}
