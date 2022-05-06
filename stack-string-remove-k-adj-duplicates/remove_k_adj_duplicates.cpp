#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string removeDuplicates(string s, int k) {
        if (s.empty()) {
            return "";
        }

        // Using a char-indexed vector instead of a hashmap to avoid overhead
        vector<vector<int>> adj_chars(26);

        adj_chars[char_to_idx(s.at(0))].push_back(1);
        stack<char> stack;
        stack.push(s.at(0));
        for (int i = 1; i < s.length(); ++i) {
            bool push_new = (stack.empty() || stack.top() != s.at(i));
            stack.push(s.at(i));
            if (push_new) {
                adj_chars[char_to_idx(stack.top())].push_back(1);
                // adj_chars[char_to_idx(stack.top())] = 1;
            } else {
                ++adj_chars[char_to_idx(stack.top())].back();
            }

            if (adj_chars[char_to_idx(stack.top())].back() == k) {
                while (adj_chars[char_to_idx(s.at(i))].back() > 0) {
                    stack.pop();
                    --adj_chars[char_to_idx(s.at(i))].back();
                }
                adj_chars[char_to_idx(s.at(i))].pop_back();
            }
        }

        string ret(stack.size(), 'X');
        for (int i = ret.length() - 1; i >= 0; --i) {
            ret[i] = stack.top();
            stack.pop();
        }

        return ret;
    }

   private:
    int char_to_idx(char c) {
        return (int)c - 97;
    }
};

int main() {
    Solution solution;
    string input;
    int k;

    // Solve this and we should be good
    // a
    input = "ayyyuuuyyyyuy";
    k = 4;
    cout << solution.removeDuplicates(input, k) << endl;

    // abc
    input = "abcyyybbbbuuuyyyyuuzzzzuuuy";
    k = 4;
    cout << solution.removeDuplicates(input, k) << endl;

    // dtpdttdwvvpctpajaggl
    input = "dtpdtaaaaaaaaappppppppppppppppppppaaaaaaaaaaxxxxxxxxxxxxxxsssssssssjjjjjjjjjjjjjjjjjjjjxxxxxxxxxxxxxxxxxxxxsssssssjjjjjjjjjjjjjjjjjjjjssssxxxxxxatdwvvpctpggggggggggggggggggggajagglaaaaaaaaaaaaaaaaaaaa";
    k = 20;
    cout << solution.removeDuplicates(input, k) << endl;

    // ps
    input = "pbbcggttciiippooaais";
    k = 2;
    cout << solution.removeDuplicates(input, k) << endl;

    // e
    input = "eyyttty";
    k = 3;
    cout << solution.removeDuplicates(input, k) << endl;

    // yftth
    input = "yftthyyyy";
    k = 4;
    cout << solution.removeDuplicates(input, k) << endl;

    // ca
    input = "abcd";
    k = 2;
    cout << solution.removeDuplicates(input, k) << endl;

    // aa
    input = "deeedbbcccbdaa";
    k = 3;
    cout << solution.removeDuplicates(input, k) << endl;
}
