#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minPartitions(string n) {
        uint8_t max_digit = 0;
        for (char& c : n) {
            max_digit = max(max_digit, (uint8_t)(c - '0'));
        }

        return max_digit;
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

    cout << "Great success!" << '\n';
}
