#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int ret = 0;
    ret = max(ret, slide(nums1, nums2));
    ret = max(ret, slide(nums2, nums1));

    return ret;
  }

 private:
  int slide(vector<int>& a, vector<int>& b) {
    int start = a.size() - 1;
    int end = 0;
    int chars_to_compare = 1;
    int ret = 0;

    while (start >= 0 && end < b.size()) {
      int longest_common_len = 0;
      for (int i = 0; i < chars_to_compare; ++i) {
        if (a[start + i] == b[end - chars_to_compare + 1 + i]) {
          ++longest_common_len;
        } else {
          ret = max(ret, longest_common_len);
          longest_common_len = 0;
        }
      }
      ret = max(ret, longest_common_len);

      --start;
      ++end;
      ++chars_to_compare;
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
  vector<int> nums1;
  vector<int> nums2;
  int output;

  nums1 = {1, 2, 3, 2, 1};
  nums2 = {3, 2, 1, 4, 7};
  output = solution.findLength(nums1, nums2);
  cout << output << '\n';
  assert(output == 3);

  cout << "Great success!" << '\n';
}
