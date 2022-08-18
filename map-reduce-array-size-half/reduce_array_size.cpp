#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> num_to_freq;
    for (auto& num : arr) {
      ++num_to_freq[num];
    }

    multimap<int, int> freq_to_num;
    for (auto& [num, freq] : num_to_freq) {
      freq_to_num.emplace(freq, num);
    }

    int elements_to_remove = arr.size() / 2;
    int ret = 0;

    for (auto it = freq_to_num.rbegin(); it != freq_to_num.rend(); ++it) {
      elements_to_remove -= it->first;
      ++ret;
      if (elements_to_remove <= 0) {
        break;
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

  /* UNIT TESTS HERE */

  cout << "Great success!" << '\n';
}
