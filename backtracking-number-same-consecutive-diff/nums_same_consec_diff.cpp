#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> numsSameConsecDiff(int n, int k) {
    if (k == 0) {
      vector<int> ret(9);
      for (int i = 1; i <= 9; ++i) {
        string str(n, '0' + i);
        ret[i - 1] = stoi(str, nullptr, 10);
      }
      return ret;
    }

    vector<int> ret;
    string str(n, '?');

    for (int i = 1; i <= 9; ++i) {
      str[0] = '0' + i;
      // explore descending
      if (i - k >= 0) {
        dfs(str, 1, i - k, k, ret);
      }
      // explore ascending
      if (i + k <= 9) {
        dfs(str, 1, i + k, k, ret);
      }
    }

    return ret;
  }

 private:
  void dfs(string& cur_string, int cur_index, int cur_digit, int& k, vector<int>& ret) {
    cur_string[cur_index] = '0' + cur_digit;
    if (cur_index == cur_string.length() - 1) {
      ret.push_back(stoi(cur_string, nullptr, 10));
      return;
    }

    // explore descending branch
    if (cur_digit - k >= 0) {
      dfs(cur_string, cur_index + 1, cur_digit - k, k, ret);
    }

    // explore ascending branch
    if (cur_digit + k <= 9) {
      dfs(cur_string, cur_index + 1, cur_digit + k, k, ret);
    }
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
  vector<int> output;

  output = solution.numsSameConsecDiff(2, 1);

  output = solution.numsSameConsecDiff(3, 7);

  cout << "Great success!" << '\n';
}
