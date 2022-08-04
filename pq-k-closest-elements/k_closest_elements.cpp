#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // proritise integers by their absolute difference to x
    auto cmp = [&x](int& a, int& b) {
      if (abs(a - x) == abs(b - x)) {
        return a < b;
      }
      return (abs(a - x) < abs(b - x));
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    for (int& num : arr) {
      pq.emplace(num);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<int> ret;
    while (!pq.empty()) {
      ret.emplace_back(pq.top());
      pq.pop();
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
