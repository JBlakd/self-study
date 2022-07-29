#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vector2D {
 public:
  Vector2D(vector<vector<int>>& vec) {
    for (vector<int>& vec_child : vec) {
      for (int& int_child : vec_child) {
        flattened.emplace_back(int_child);
      }
    }

    it = flattened.begin();
  }

  int next() {
    int old_val = *(it);
    ++it;
    return old_val;
  }

  bool hasNext() {
    if (flattened.empty()) {
      return false;
    }

    return (it <= flattened.end() - 1);
  }

 private:
  vector<int> flattened;
  vector<int>::iterator it;
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
}
