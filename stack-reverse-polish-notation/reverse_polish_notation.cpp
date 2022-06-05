#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> my_stack;

        for (string& token : tokens) {
            if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
                int op_2 = my_stack.top();
                my_stack.pop();
                int op_1 = my_stack.top();
                my_stack.pop();
                switch (token[0]) {
                    case '+':
                        my_stack.push(op_1 + op_2);
                        break;
                    case '-':
                        my_stack.push(op_1 - op_2);
                        break;
                    case '*':
                        my_stack.push(op_1 * op_2);
                        break;
                    case '/':
                        my_stack.push(op_1 / op_2);
                        break;
                }
            } else {
                my_stack.push(stoi(token, nullptr, 10));
            }
        }

        return my_stack.top();
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
    vector<string> tokens;

    // 22
    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << solution.evalRPN(tokens) << '\n';

    // 6
    tokens = {"4", "13", "5", "/", "+"};
    cout << solution.evalRPN(tokens) << '\n';

    // 9
    tokens = {"2", "1", "+", "3", "*"};
    cout << solution.evalRPN(tokens) << '\n';
}
