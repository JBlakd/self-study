#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int max = 0;
        for (int i = 0; i < special.size(); ++i) {
            if (i == 0) {
                // cout << "Between " << bottom << " and " << special[i] - 1 << " are " << special[i] - bottom << " floors.\n";
                if (special[i] - 1 - bottom > max) {
                    max = special[i] - bottom;
                }
            } else {
                // cout << "Between " << special[i - 1] + 1 << " and " << special[i] - 1 << " are " << special[i] - special[i - 1] - 1 << " floors.\n";
                if (special[i] - special[i - 1] > max) {
                    max = special[i] - special[i - 1] - 1;
                }
            }
        }

        // cout << "Between " << top << " and " << special.back() + 1 << " are " << top - (special.back() + 1) + 1 << " floors.\n";
        if (top - (special.back() + 1) + 1 > max) {
            max = top - (special.back() + 1) + 1;
        }
        return max;
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
    int bottom;
    int top;
    vector<int> special;

    bottom = 2;
    top = 9;
    special = {4};
    cout << solution.maxConsecutive(bottom, top, special) << endl;

    bottom = 2;
    top = 9;
    special = {4, 6};
    cout << solution.maxConsecutive(bottom, top, special) << endl;

    bottom = 6;
    top = 8;
    special = {7, 6, 8};
    cout << solution.maxConsecutive(bottom, top, special) << endl;
}
