#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool digitCount(string num) {
        vector<int> num_vect(num.length());
        // ascii '0' is 48
        for (int i = 0; i < num.length(); ++i) {
            num_vect[i] = num[i] - 48;
        }

        for (int i = 0; i < num.length(); ++i) {
            if (num[i] - 48 >= num.length()) {
                return false;
            }
            --num_vect[num[i] - 48];
        }

        for (int i = 0; i < num.length(); ++i) {
            if (num_vect[i] != 0) {
                return false;
            }
        }

        return true;
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
    string num;

    // 1
    num = "1210";
    cout << solution.digitCount(num) << endl;

    // 0
    num = "030";
    cout << solution.digitCount(num) << endl;
}
