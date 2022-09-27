#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string pushDominoes(string dominoes) {
    if (dominoes.length() == 1) {
      return dominoes;
    }

    int prev_domino = 0;
    for (int i = 1; i < dominoes.length(); ++i) {
      if (dominoes[i] == '.') {
        continue;
      }

      int num_to_process = i - prev_domino + 1;

      if (dominoes[i] == 'L') {
        if (dominoes[prev_domino] == 'R') {
          num_to_process /= 2;
          for (int j = 0; j < num_to_process; ++j) {
            dominoes[prev_domino + j] = 'R';
          }
          for (int j = 0; j < num_to_process; ++j) {
            dominoes[i - j] = 'L';
          }
        } else {
          for (int j = 0; j < num_to_process; ++j) {
            dominoes[prev_domino + j] = 'L';
          }
        }
      } else {
        if (dominoes[prev_domino] == 'R') {
          for (int j = 0; j < num_to_process; ++j) {
            dominoes[prev_domino + j] = 'R';
          }
        }
      }

      prev_domino = i;
    }

    if (dominoes[prev_domino] == 'R') {
      for (int i = prev_domino; i < dominoes.length(); ++i) {
        dominoes[i] = 'R';
      }

      if (prev_domino == 0) {
        return dominoes;
      }

      int i = prev_domino - 1;
      while (i > 0 && dominoes[i] == '.') {
        --i;
      }
      if (dominoes[i] == 'R') {
        while (i < prev_domino) {
          dominoes[i] = 'R';
          ++i;
        }
      }
    }

    return dominoes;
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
  string dominoes;
  string output;

  dominoes = ".R.";
  output = solution.pushDominoes(dominoes);
  cout << output << '\n';
  assert(output == ".RR");

  dominoes = "R.";
  output = solution.pushDominoes(dominoes);
  cout << output << '\n';
  assert(output == "RR");

  cout << "Great success!" << '\n';
}
