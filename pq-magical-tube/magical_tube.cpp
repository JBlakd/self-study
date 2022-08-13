#include <cassert>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> elements(int Q, vector<vector<int>> query) {
    vector<int> ret;

    // <num, freq>
    unordered_map<int, int> num_freq;
    // <freq, num>
    map<int, stack<int>> freq_num;

    for (vector<int>& q : query) {
      if (q[0] == 1) {
        ++num_freq[q[1]];
        freq_num[num_freq[q[1]]].emplace(q[1]);
      } else {
        // Add to ret the front of the queue of the highest frequency
        ret.emplace_back(freq_num.rbegin()->second.top());
        freq_num.rbegin()->second.pop();
        if (freq_num.rbegin()->second.empty()) {
          freq_num.erase(freq_num.rbegin()->first);
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
  int Q;
  vector<vector<int>> query;
  vector<int> output;

  Q = 3;
  query = {{1, 62}, {1, 49}, {2, -1}};
  output = solution.elements(Q, query);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{49}));

  cout << "Great success!" << '\n';
}
