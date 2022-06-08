#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);

        for (int i = 0; i <= n; ++i) {
            ret[i] = count_bits(i);
        }

        return ret;
    }

   private:
    int count_bits(int num) {
        // Kernighan's Algorithm for counting bits

        int count = 0;
        while (num) {
            num = num & num - 1;
            ++count;
        }
        return count;
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
