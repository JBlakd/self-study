#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    vector<int> uf(26);
    for (int i = 0; i < 26; ++i) {
      uf[i] = i;
    }

    // satisfy all equalities first
    for (auto& eq : equations) {
      if (eq[1] == '=') {
        int p = eq[0] - 'a';
        int q = eq[3] - 'a';
        connect(uf, p, q);
      }
    }

    // check for inequality contradictions
    for (auto& eq : equations) {
      if (eq[1] == '!') {
        int p = eq[0] - 'a';
        int q = eq[3] - 'a';
        if (connected(uf, p, q)) {
          return false;
        }
      }
    }

    return true;
  }

 private:
  // returns the component that p belongs to
  int find(vector<int>& uf, int& p) {
    // find root of p's component
    int root = p;
    while (root != uf[root]) {
      root = uf[root];
    }

    // now that we know p and its root, compress the path by making every path node point to root
    while (p != root) {
      int next = uf[p];
      uf[p] = root;
      p = next;
    }

    return root;
  }

  bool connected(vector<int>& uf, int& p, int& q) {
    return find(uf, p) == find(uf, q);
  }

  void connect(vector<int>& uf, int& p, int& q) {
    // check if already connected
    if (connected(uf, p, q)) {
      return;
    }

    int p_root = find(uf, p);
    int q_root = find(uf, q);

    uf[p_root] = q_root;
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
  vector<string> equations;
  bool output;

  equations = {"a==b", "e==c", "b==c", "a!=e"};
  output = solution.equationsPossible(equations);
  cout << output << '\n';
  assert(output == false);

  cout << "Great success!" << '\n';
}
