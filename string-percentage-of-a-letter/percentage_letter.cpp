#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (char s_c : s) {
            if (s_c == letter) {
                ++count;
            }
        }

        double percentage_double = ((double)count / (double)s.length()) * 100.0;
        return (int)percentage_double;
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
    char letter;

    s = "ivanbentaohu";
    letter = 'n';
    cout << solution.percentageLetter(s, letter) << endl;

    s = "foobar";
    letter = 'o';
    cout << solution.percentageLetter(s, letter) << endl;

    s = "jjjj";
    letter = 'k';
    cout << solution.percentageLetter(s, letter) << endl;

    s = "jjjj";
    letter = 'j';
    cout << solution.percentageLetter(s, letter) << endl;
}
