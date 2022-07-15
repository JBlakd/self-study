#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
    vector<int> ans_1(colors.size(), -1);
    bool ans_1_lost_cause = false;
    process_array(ans_1, ans_1_lost_cause, colors, 1);

    vector<int> ans_2(colors.size(), -1);
    bool ans_2_lost_cause = false;
    process_array(ans_2, ans_2_lost_cause, colors, 2);

    vector<int> ans_3(colors.size(), -1);
    bool ans_3_lost_cause = false;
    process_array(ans_3, ans_3_lost_cause, colors, 3);

    vector<int> ret(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      switch (queries[i][1]) {
        case 1:
          ret[i] = ans_1[queries[i][0]];
          break;
        case 2:
          ret[i] = ans_2[queries[i][0]];
          break;
        case 3:
          ret[i] = ans_3[queries[i][0]];
          break;
      }
    }

    return ret;
  }

 private:
  void process_array(vector<int>& ans, bool& lost_cause, vector<int>& colors, int target) {
    int i = 0;
    while (i < colors.size()) {
      int lo = i;
      int hi = i;
      while (true) {
        if (hi < colors.size() && colors[hi] == target) {
          // discovered to the right first
          for (int j = i; j <= hi; ++j) {
            ans[j] = hi - j;
          }

          i = hi;
          break;
        }
        ++hi;

        if (lo >= 0 && colors[lo] == target) {
          ans[i] = i - lo;
          break;
        }
        --lo;

        // no valid colour discovered, abort this array
        if (lo < 0 && hi >= colors.size()) {
          lost_cause = true;
          break;
        }
      }

      if (lost_cause) {
        break;
      }

      ++i;
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
  vector<int> colors;
  vector<vector<int>> queries;
  vector<int> output;

  colors = {1, 1, 2, 1, 3, 2, 1, 3, 3};
  queries = {{1, 3}, {2, 2}, {6, 1}};
  output = solution.shortestDistanceColor(colors, queries);
  print_vector(output);
  assert((output == vector<int>{3, 0, 0}));
  cout << '\n';

  cout << "Great success!" << '\n';
}
