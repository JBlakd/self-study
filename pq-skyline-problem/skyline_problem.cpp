#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // <height, right>
    priority_queue<pair<int, int>> pq;
    vector<vector<int>> ret;
    int rightmost = 0;

    for (int i = 0; i < buildings.size(); ++i) {
      vector<int>& building = buildings[i];
      int& left = building[0];
      int& right = building[1];
      int& height = building[2];

      // current scan == left
      // pop ended buildings from the pq
      while (!pq.empty() && pq.top().second <= left) {
        pq.pop();
      }

      // edge case all buildings eliminated, we we need to account for the previous rightmost building's endpoint
      if (pq.empty() && i > 0) {
        ret.push_back(vector<int>{rightmost, 0});
      }

      // check if current point is encompassed by the highest non-ended building
      if (pq.empty() || height > pq.top().first) {
        if (!ret.empty() && left == ret.back()[0]) {
          ret.pop_back();
        }
        ret.push_back(vector<int>{left, height});
      } else if (height != pq.top().first) {
        ret.push_back(vector<int>{pq.top().second, height});
      }

      // add current building into pq
      pq.emplace(height, right);
      rightmost = max(rightmost, right);
    }

    ret.push_back(vector<int>{rightmost, 0});
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
  vector<vector<int>> buildings;
  vector<vector<int>> output;

  // buildings = {{1, 2, 1}, {1, 2, 2}, {1, 2, 3}, {2, 3, 1}, {2, 3, 2}, {2, 3, 3}};
  // output = solution.getSkyline(buildings);

  buildings = {{0, 2, 3}, {0, 5, 3}};
  output = solution.getSkyline(buildings);

  cout << "Great success!" << '\n';
}
