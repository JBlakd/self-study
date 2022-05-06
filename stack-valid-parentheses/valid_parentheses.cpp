#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                parentheses.push(c);
            } else {
                switch (c) {
                    case ')':
                        if (parentheses.empty() || parentheses.top() != '(') {
                            return false;
                        } else {
                            parentheses.pop();
                        }
                        break;
                    case '}':
                        if (parentheses.empty() || parentheses.top() != '{') {
                            return false;
                        } else {
                            parentheses.pop();
                        }
                        break;
                    case ']':
                        if (parentheses.empty() || parentheses.top() != '[') {
                            return false;
                        } else {
                            parentheses.pop();
                        }
                        break;
                }
            }
        }

        return parentheses.empty();
    }
};

int main() {
    Solution solution;
    string input;

    input = "()";
    cout << solution.isValid(input) << endl;

    input = "()[]{}";
    cout << solution.isValid(input) << endl;

    input = "(]";
    cout << solution.isValid(input) << endl;

    input = "]";
    cout << solution.isValid(input) << endl;
}
