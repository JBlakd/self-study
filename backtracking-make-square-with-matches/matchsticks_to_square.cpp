#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool makesquare(vector<int>& matchsticks) {
    if (matchsticks.empty()) {
      return false;
    }

    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4 != 0) {
      return false;
    }

    // sort matchsticks from large to small, serves to optimise pruning
    // sorting time will be dominated by the algorithm's time anyway
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());

    // array representing 4 sides
    vector<int> sides(4, 0);

    return dfs(sides, matchsticks, sum / 4, 0);
  }

 private:
  bool dfs(vector<int>& sides, vector<int>& matchsticks, const int target_side_len, int index) {
    // After using all matchsticks, check equality of square's sides
    if (index == matchsticks.size()) {
      return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
    }

    for (int i = 0; i < sides.size(); ++i) {
      int& side = sides[i];

      // don't explore the matchstick that will result in an overly-long side
      if (side + matchsticks[index] > target_side_len) {
        continue;
      }

      // even more pruning: we don't care to assign a specific length to a specific side
      // if the next recursion tree results in the same outcome as a previously-explored one,
      // then don't even bother going down it
      int j = i;
      while (--j >= 0)
        if (sides[i] == sides[j])
          break;
      if (j != -1) continue;

      side += matchsticks[index];
      if (dfs(sides, matchsticks, target_side_len, index + 1)) {
        // dfs has returned true, answer found, don't explore anymore.
        return true;
      }
      side -= matchsticks[index];
    }

    return false;
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
