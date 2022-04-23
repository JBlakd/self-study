#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    int s_i = 0;
    int t_i = 0;
    int s_del = 0;
    int t_del = 0;

    while (s_i < s.length()) {
      s_del = s_i;
      if (s.at(s_i) != '#') {
        // s_del = s_i;
      } else {
        while (s_del >= 0 && (s.at(s_del) == 'A' || s.at(s_del) == '#')) {
          s_del--;
        }
        if (s_del >= 0) {
          s[s_del] = 'A';
        }
      }

      s_i++;
    }

    while (t_i < t.length()) {
      t_del = t_i;
      if (t.at(t_i) != '#') {
        // t_del = t_i;
      } else {
        while (t_del >= 0 && (t.at(t_del) == 'A' || t.at(t_del) == '#')) {
          t_del--;
        }
        if (t_del >= 0) {
          t[t_del] = 'A';
        }
      }

      t_i++;
    }

    // cout << s << ", " << t << "\n";
    // scan through both strings to see how many normal characters
    int s_normal_count = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s.at(i) != '#' && s.at(i) != 'A') {
        s_normal_count++;
      }
    }
    int t_normal_count = 0;
    for (int i = 0; i < t.length(); i++) {
      if (t.at(i) != '#' && t.at(i) != 'A') {
        t_normal_count++;
      }
    }

    if (s_normal_count != t_normal_count) {
      return false;
    }

    s_i = 0;
    t_i = 0;
    int s_count = 0;
    int t_count = 0;
    while (true) {
      if (s_count == s_normal_count || t_count == t_normal_count) {
        return true;
      }

      while (s.at(s_i) == '#' || s.at(s_i) == 'A') {
        s_i++;
        if (s_i == s.length()) {
          return (s_count == t_count);
        }
      }
      while (t.at(t_i) == '#' || t.at(t_i) == 'A') {
        t_i++;
        if (t_i == t.length()) {
          return (s_count == t_count);
        }
      }

      if (s.at(s_i) != t.at(t_i)) {
        return false;
      }

      s_i++;
      t_i++;
      s_count++;
      t_count++;
    }
  }
};

int main() {
  Solution solution;
  printf("%s", solution.backspaceCompare("a#c", "b") ? "true\n" : "false\n");              // false
  printf("%s", solution.backspaceCompare("a##c", "#a#c") ? "true\n" : "false\n");          // true
  printf("%s", solution.backspaceCompare("ab#cc#", "ad#c") ? "true\n" : "false\n");        // true
  printf("%s", solution.backspaceCompare("isfcow#", "isfco#w#") ? "true\n" : "false\n");   // false
  printf("%s", solution.backspaceCompare("ab##", "c#d#") ? "true\n" : "false\n");          // true
  printf("%s", solution.backspaceCompare("ab#c", "ad#c") ? "true\n" : "false\n");          // true
  printf("%s", solution.backspaceCompare("ab#c", "ad#f#c") ? "true\n" : "false\n");        // true
  printf("%s", solution.backspaceCompare("xywrrmp", "xymrrm#p") ? "true\n" : "false\n");   // false
  printf("%s", solution.backspaceCompare("bxj##tw", "bxo#j##tw") ? "true\n" : "false\n");  // true
}
