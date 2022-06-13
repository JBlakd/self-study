#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
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

    /* UNIT TESTS HERE */

    cout << "Great success!" << '\n';
}
