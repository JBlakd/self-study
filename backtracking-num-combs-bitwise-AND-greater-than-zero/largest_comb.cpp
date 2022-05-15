#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int largestCombination(vector<int>& candidates) {
        // count the number of candidates with MSB 0
        int count = 0;
        int msb = (1 << 31);
        for (int& candidate : candidates) {
            if (msb | candidate) {
                continue;
            }
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
    vector<int> candidates;

    candidates = {13, 44, 58, 17, 23, 13, 87, 79, 91, 47, 86, 90, 4, 93, 18, 75, 29, 66, 43, 60, 19, 3, 28};
    cout << solution.largestCombination(candidates) << endl;

    candidates = {16, 17, 71, 62, 12, 24, 14};
    cout << solution.largestCombination(candidates) << endl;

    candidates = {8, 8};
    cout << solution.largestCombination(candidates) << endl;
}
