#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }

        stack<int> my_stack;
        vector<bool> resolved(s.length(), false);

        for (int i = 0; i < s.length(); ++i) {
            if (my_stack.empty()) {
                if (s[i] == '(') {
                    my_stack.push(i);
                }
                continue;
            }

            if (s[i] == ')') {
                resolved[my_stack.top()] = true;
                my_stack.pop();
                resolved[i] = true;
            } else {
                my_stack.push(i);
            }
        }

        // Loop over resolved array for longest contiguous true
        int ret = 0;
        int cur_contig_len = 0;
        for (int i = 0; i < resolved.size(); ++i) {
            if (resolved[i]) {
                ++cur_contig_len;
            } else {
                cur_contig_len = 0;
            }

            ret = max(ret, cur_contig_len);
        }

        return ret;
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

    // 2
    s = "()(()";
    cout << solution.longestValidParentheses(s) << '\n';

    // 6 (sum of two continuout well-formed strings)
    s = "()(())";
    cout << solution.longestValidParentheses(s) << '\n';

    // 4 (max length of two discontinuous well-formed strings)
    s = "())(())";
    cout << solution.longestValidParentheses(s) << '\n';

    // 0
    s = ")(";
    cout << solution.longestValidParentheses(s) << '\n';

    // 2
    s = "(()";
    cout << solution.longestValidParentheses(s) << '\n';

    // 4
    s = ")()())";
    cout << solution.longestValidParentheses(s) << '\n';

    // 4
    s = ")(()))";
    cout << solution.longestValidParentheses(s) << '\n';
}
