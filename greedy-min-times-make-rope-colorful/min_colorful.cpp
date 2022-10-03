#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(string colors, vector<int>& neededTime) {
    if (colors.length() == 1) {
      return 0;
    }

    // keep the maximum of each group
    int total_time = neededTime[0];
    int group_max_summed = 0;
    int cur_group_max = neededTime[0];
    for (int i = 1; i < colors.length(); ++i) {
      total_time += neededTime[i];

      if (colors[i] != colors[i - 1]) {
        group_max_summed += cur_group_max;
        cur_group_max = neededTime[i];
      } else {
        cur_group_max = max(cur_group_max, neededTime[i]);
      }
    }
    group_max_summed += cur_group_max;

    return total_time - group_max_summed;
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
  string colors;
  vector<int> neededTime;
  int output;

  colors = "abaac";
  neededTime = {1, 2, 3, 4, 5};
  output = solution.minCost(colors, neededTime);
  cout << output << '\n';
  assert(output == 3);

  cout << "Great success!" << '\n';
}
