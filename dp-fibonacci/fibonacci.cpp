#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int fib(int n) {
        // Bottom up dp
        vector<int> vect(n + 1);
        vect[0] = 0;
        if (n == 0) {
            return 0;
        }
        vect[1] = 1;
        if (n == 1) {
            return 1;
        }

        for (int i = 2; i <= n; ++i) {
            vect[i] = vect[i - 1] + vect[i - 2];
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
}
