#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.size() == 1) {
            return people;
        }

        // pre-allocate ret matrix of same dimension as input, all with value -1
        vector<vector<int>> ret(people.size(), vector<int>(2, -1));

        // sort input by ascending height
        sort(people.begin(), people.end());

        for (auto& person : people) {
            // person[1] == pos
            int num_pos_i = -1;
            for (int i = 0; i < ret.size(); ++i) {
                if (ret[i][0] == -1 || ret[i][0] == person[0]) {
                    ++num_pos_i;
                }

                if (num_pos_i == person[1]) {
                    ret[i] = person;
                    break;
                }
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
    vector<vector<int>> people;
    vector<vector<int>> output;

    people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    output = solution.reconstructQueue(people);
    for (auto& vec : output) {
        print_vector(vec);
        cout << ',';
    }
    cout << '\n';

    people = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
    output = solution.reconstructQueue(people);
    for (auto& vec : output) {
        print_vector(vec);
        cout << ',';
    }
    cout << '\n';
}
