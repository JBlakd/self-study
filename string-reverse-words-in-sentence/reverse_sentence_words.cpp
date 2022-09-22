#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int front = 0;
    int back = -1;

    while (front <= s.length()) {
      if (front < s.length() && s[front] != ' ') {
        ++front;
        continue;
      }

      int back_temp = back + 1;
      int front_temp = front - 1;

      while (back_temp < front_temp) {
        swap(s, back_temp, front_temp);
        ++back_temp;
        --front_temp;
      }

      back = front;
      ++front;
    }

    return s;
  }

 private:
  void swap(string& s, int& a, int& b) {
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
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
