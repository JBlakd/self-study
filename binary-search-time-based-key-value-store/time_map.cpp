#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
 public:
  TimeMap() {
    time_map.clear();
  }

  void set(string key, string value, int timestamp) {
    auto map_it = time_map.find(key);
    if (map_it == time_map.end()) {
      time_map[key] = make_pair(vector<int>(), vector<string>());
      map_it = time_map.find(key);
    }

    auto &[timestamp_vec, string_vec] = map_it->second;
    timestamp_vec.push_back(timestamp);
    string_vec.push_back(value);
  }

  string get(string key, int timestamp) {
    auto map_it = time_map.find(key);
    if (map_it == time_map.end()) {
      return "";
    }

    auto &[timestamp_vec, string_vec] = map_it->second;

    auto timestamp_it = lower_bound(timestamp_vec.begin(), timestamp_vec.end(), timestamp);
    if (timestamp_it == timestamp_vec.end()) {
      // requested timestamp is later than the latest timestamp
      // return the last timestamp
      return string_vec.back();
    } else if (*(timestamp_it) == timestamp) {
      // matching timestamp found
      int index = timestamp_it - timestamp_vec.begin();
      return string_vec[index];
    } else if (timestamp_it == timestamp_vec.begin()) {
      // returned first timestamp despite not matching with the first timestamp
      // means the requested timestamp is earlier than the earliest timestamp
      return "";
    } else {
      // all the other cases ensure that the requested timestamp will be the one before lower_bound
      int index = timestamp_it - timestamp_vec.begin() - 1;
      return string_vec[index];
    }
  }

 private:
  unordered_map<string, pair<vector<int>, vector<string>>> time_map;
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
}
