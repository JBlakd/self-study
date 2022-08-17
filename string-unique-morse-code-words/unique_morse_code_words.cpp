#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    unordered_set<string> encountered;

    for (string& word : words) {
      string morse_encode = "";
      for (char& c : word) {
        morse_encode.append(morse[c - 'a']);
      }
      encountered.emplace(morse_encode);
    }

    return encountered.size();
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
