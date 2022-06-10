#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        for (int i = 0; i <= 15; ++i) {
            if (b[i] != b[31 - i]) {
                b.flip(i);
                b.flip(31 - i);
            }
        }

        return b.to_ulong();
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
