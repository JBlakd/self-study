#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    unordered_map<int, uint64_t> dp;
    for (int& num : arr) {
      dp[num] = 1;
    }

    sort(arr.begin(), arr.end());

    for (int& subtree_root : arr) {
      for (int& factor : arr) {
        if (factor > subtree_root) {
          break;
        }

        if (subtree_root % factor == 0 && dp.find(subtree_root / factor) != dp.end()) {
          dp[subtree_root] += max(dp[factor], dp[subtree_root / factor]) % 1000000007;
        }
      }
    }

    uint64_t ret = 0;
    for (auto& [key, val] : dp) {
      ret += val;
    }

    return (int)(ret % 1000000007UL);
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
  int output;

  arr = {2, 4, 128, 256, 1024};
  output = solution.numFactoredBinaryTrees(arr);
  cout << output << '\n';
  assert(output == 20);

  cout << "Great success!" << '\n';
}
