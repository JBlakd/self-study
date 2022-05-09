#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        //                        0   1     2      3      4      5      6      7       8      9
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        string local_ans = "";
        helper(digits, local_ans, mapping, ret);

        return ret;
    }

   private:
    void helper(string& digits, string& local_ans, vector<string>& mapping, vector<string>& ret) {
        if (local_ans.size() == digits.size()) {
            ret.push_back(local_ans);
            return;
        }
        int digit = digits[local_ans.size()] - 48;
        for (char next_level_char : mapping[digit]) {
            local_ans.append(1, next_level_char);
            helper(digits, local_ans, mapping, ret);
            local_ans.pop_back();
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
    string digits;
    vector<string> output;

    digits = "";
    output = solution.letterCombinations(digits);
    print_vector(output);
    cout << endl;

    digits = "2";
    output = solution.letterCombinations(digits);
    print_vector(output);
    cout << endl;

    digits = "23";
    output = solution.letterCombinations(digits);
    print_vector(output);
    cout << endl;

    digits = "456";
    output = solution.letterCombinations(digits);
    print_vector(output);
    cout << endl;
}
