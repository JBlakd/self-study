#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int unit_buckets[1001] = {0};

        for (auto& box : boxTypes) {
            unit_buckets[box[1]] += box[0];
        }

        int ret = 0;
        for (int i = 1000; i > 0; --i) {
            if (unit_buckets[i] > 0) {
                int boxes_taken = min(truckSize, unit_buckets[i]);
                truckSize -= boxes_taken;
                ret += (boxes_taken * i);
            }

            if (truckSize == 0) {
                break;
            }
        }

        return ret;
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

    /* UNIT TESTS HERE */

    cout << "Great success!" << '\n';
}
