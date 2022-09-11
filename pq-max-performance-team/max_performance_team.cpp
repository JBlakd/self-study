#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    // sort engineers by efficiency
    priority_queue<pair<int, int>> efficiency_max_pq;
    for (int i = 0; i < efficiency.size(); ++i) {
      efficiency_max_pq.emplace(efficiency[i], speed[i]);
    }

    // iterate through engineers, forming k-sized teams with maximum possible speeds, limiting team to size k using a pq
    long ret = 0;
    long speed_sum = 0;
    int min_efficiency = 100000001;
    priority_queue<int, vector<int>, greater<int>> speed_min_pq;
    while (!efficiency_max_pq.empty()) {
      auto [e, s] = efficiency_max_pq.top();
      efficiency_max_pq.pop();
      speed_min_pq.emplace(s);
      speed_sum += s;

      if (speed_min_pq.size() <= k) {
        min_efficiency = min(min_efficiency, e);
      } else {
        if (speed_min_pq.top() != s) {
          min_efficiency = min(min_efficiency, e);
        }

        speed_sum -= speed_min_pq.top();
        speed_min_pq.pop();
      }

      // calculate the efficiency of each team and record it as the global maximum if it beats the current maximum
      ret = max(ret, speed_sum * min_efficiency);
    }

    return ret % 1000000007;
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
  int n;
  vector<int> speed;
  vector<int> efficiency;
  int k;
  int output;

  n = 6;
  speed = {2, 10, 3, 1, 5, 8};
  efficiency = {5, 4, 3, 9, 7, 2};
  k = 2;
  output = solution.maxPerformance(n, speed, efficiency, k);
  cout << output << '\n';
  assert(output == 60);

  cout << "Great success!" << '\n';
}
