#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class MyCalendar {
 public:
  MyCalendar() {
    treemap.clear();
  }

  bool book(int start, int end) {
    // gotta store endpoints because ordered set does not allow for logarithmic search for element before
    // find the event which ends strictly after the proposed event's start
    map<int, int>::iterator next = treemap.upper_bound(start);

    // If next ends before the proposed event's start, we have a problem
    if (next != treemap.end() && next->second < end) {
      return false;
    }

    // all good now
    treemap.emplace(end, start);
    return true;
  }

 private:
  // a treemap of intervals sorted by start date, value end date
  map<int, int> treemap;
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
  MyCalendar solution;
  assert(solution.book(33, 41) == true);
  assert(solution.book(47, 50) == true);

  cout << "Great success!" << '\n';
}
