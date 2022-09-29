#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // find closest element
    // must either be lower_bound or lower_bound - 1
    auto it = lower_bound(arr.begin(), arr.end(), x);
    if (it != arr.begin() && it != arr.end() && x - *(it - 1) <= *(it)-x) {
      --it;
    }

    // check edge cases
    if (it == arr.begin()) {
      return vector<int>(arr.begin(), arr.begin() + k);
    }
    if (it == arr.end() - 1 || it == arr.end()) {
      return vector<int>(arr.end() - k, arr.end());
    }

    // it's somewhere in the middle
    // the range between lo and hi is non-inclusive, k is the count so far
    int it_idx = it - arr.begin();
    int lo = it_idx - 1;
    int hi = it_idx + 1;
    --k;

    while (k > 0) {
      // check edge cases
      if (lo < 0) {
        hi += k;
        k = 0;
        break;
      }
      if (hi >= arr.size()) {
        lo -= k;
        k = 0;
        break;
      }

      if (arr[hi] - x == x - arr[lo]) {
        // equal distance, favour lo
        --lo;
      } else if (arr[hi] - x < x - arr[lo]) {
        // hi is closer, favour hi
        ++hi;
      } else {
        // lo is closer, favour lo
        --lo;
      }

      --k;
    }

    return vector<int>(arr.begin() + 1 + lo, arr.begin() + hi);
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
  vector<int> arr;
  int k;
  int x;
  vector<int> output;

  arr = {0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
  k = 3;
  x = 5;
  output = solution.findClosestElements(arr, k, x);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{3, 3, 4}));

  arr = {1, 2, 3, 4, 5};
  k = 4;
  x = -1;
  output = solution.findClosestElements(arr, k, x);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{1, 2, 3, 4}));

  arr = {1, 2, 3, 4, 5};
  k = 4;
  x = 3;
  output = solution.findClosestElements(arr, k, x);
  print_vector(output);
  cout << '\n';
  assert((output == vector<int>{1, 2, 3, 4}));

  cout << "Great success!" << '\n';
}
