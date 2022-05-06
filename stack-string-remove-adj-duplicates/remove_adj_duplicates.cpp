#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string removeDuplicates(string s) {
        if (s.empty()) {
            return "";
        }

        stack<char> stack;
        stack.push(s.at(0));
        for (int i = 1; i < s.length(); ++i) {
            if (stack.empty() || s.at(i) != stack.top()) {
                stack.push(s.at(i));
            } else {
                stack.pop();
            }
        }

        string ret(stack.size(), 'X');
        for (int i = ret.length() - 1; i >= 0; --i) {
            ret[i] = stack.top();
            stack.pop();
        }

        return ret;
    }
};

int main() {
    Solution solution;
    string input;

    // ca
    input = "abbaca";
    cout << solution.removeDuplicates(input) << endl;

    // ay
    input = "azxxzy";
    cout << solution.removeDuplicates(input) << endl;

    // xyij
    input = "xabbayiggyyj";
    cout << solution.removeDuplicates(input) << endl;
}
