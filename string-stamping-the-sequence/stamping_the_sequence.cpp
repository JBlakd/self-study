#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ret;

    while (true) {
      bool is_finished = true;
      // slide the window across the entire target string
      for (int i = 0; i <= target.length() - stamp.length(); ++i) {
        // check if the window is a matching substring
        if (is_matching_substring(stamp, target, i)) {
          for (int j = 0; j < stamp.length(); ++j) {
            target[i + j] = '*';
          }
          ret.push_back(i);
          is_finished = false;
        }
      }

      if (is_finished) {
        break;
      }
    }

    // check if every letter has been converted to *
    for (char& c : target) {
      if (c != '*') {
        return {};
      }
    }

    return (ret.size() <= 10 * target.length()) ? vector<int>(ret.rbegin(), ret.rend()) : vector<int>{};
  }

 private:
  bool is_matching_substring(string& stamp, string& target, int idx) {
    bool is_all_asterisks = true;
    for (int i = 0; i < stamp.length(); ++i) {
      if (target[idx + i] == '*') {
        continue;
      }

      if (target[idx + i] == stamp[i]) {
        is_all_asterisks = false;
        continue;
      }

      return false;
    }

    return (!is_all_asterisks);
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
  string stamp;
  string target;
  vector<int> output;

  stamp = "abc";
  target = "ababc";
  output = solution.movesToStamp(stamp, target);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{0, 2}));

  cout << "Great success!" << '\n';
}
