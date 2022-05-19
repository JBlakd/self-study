#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            count_odd(i, count, s);
            count_even(i, count, s);
        }
        return count;
    }

   private:
    void count_odd(int mid, int& count, string& s) {
        int left = mid;
        int right = mid;
        while (left >= 0 && right < s.length()) {
            if (s[left] == s[right]) {
                ++count;
            } else {
                break;
            }

            --left;
            ++right;
        }
    }

    // mid denotes the left-skewed element
    void count_even(int mid, int& count, string& s) {
        int left = mid;
        int right = mid + 1;
        while (left >= 0 && right < s.length()) {
            if (s[left] == s[right]) {
                ++count;
            } else {
                break;
            }

            --left;
            ++right;
        }
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
    string s;

    s = "abc";
    cout << solution.countSubstrings(s) << endl;

    s = "aaa";
    cout << solution.countSubstrings(s) << endl;

    // 14
    s = "flaabaalb";
    cout << solution.countSubstrings(s) << endl;
}
