#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int ret = 0;
    int cur_distance = 0;
    int cur_station_idx = -1;

    priority_queue<int> pq;
    while (cur_distance < target) {
      // travel as much distance as possible (empty the tank)
      cur_distance += startFuel;
      startFuel = 0;
      if (cur_distance >= target) {
        return ret;
      }
      while (cur_station_idx < (int)stations.size() - 1 && stations[cur_station_idx + 1][0] <= cur_distance) {
        pq.emplace(stations[cur_station_idx + 1][1]);
        ++cur_station_idx;
      }

      // refuel until you can get to the next station at least if not at last station
      if (cur_station_idx < stations.size() - 1) {
        while (cur_distance + startFuel < stations[cur_station_idx + 1][0]) {
          if (pq.empty()) {
            // Saul Gone (end of the road pal)
            return -1;
          }
          startFuel += pq.top();
          pq.pop();
          ++ret;
        }
      } else {
        while (cur_distance + startFuel < target) {
          if (pq.empty()) {
            // Saul Gone (end of the road pal)
            return -1;
          }
          startFuel += pq.top();
          pq.pop();
          ++ret;
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
  int target;
  int startFuel;
  vector<vector<int>> stations;
  int output;

  target = 100;
  startFuel = 10;
  stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
  output = solution.minRefuelStops(target, startFuel, stations);
  cout << output << '\n';
  assert(output == 2);

  cout << "Great success!" << '\n';
}
