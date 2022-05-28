#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPerfectSquare(int num) {
        int lo = 0;
        int hi = num;

        while (lo <= hi) {
            int mid = lo + ((hi - lo) / 2);
            uint64_t mid_sq = (uint64_t)mid * mid;
            if (mid_sq > (uint64_t)num) {
                hi = mid - 1;
            } else if (mid_sq < (uint64_t)num) {
                lo = mid + 1;
            } else {
                return true;
            }
        }

        return false;
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

    // 1
    cout << solution.isPerfectSquare(16) << endl;
    // 0
    cout << solution.isPerfectSquare(14) << endl;
    // 1
    cout << solution.isPerfectSquare(1) << endl;
    // 0
    cout << solution.isPerfectSquare(2147483647) << endl;
}
