#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }

        vector<int> vect(n + 1);
        vect[0] = 0;
        vect[1] = 1;
        vect[2] = 1;

        for (int i = 3; i <= n; ++i) {
            vect[i] = vect[i - 3] + vect[i - 2] + vect[i - 1];
        }

        return vect[n];
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
    cout << solution.tribonacci(0) << endl;
    cout << solution.tribonacci(4) << endl;
}
