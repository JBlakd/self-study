#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Don't use max, too close to overflow
        vector<vector<int>> ret(mat.size(), vector<int>(mat[0].size(), numeric_limits<int>::max() - 100000));
        // two pass DP
        // Firstly from top left to bottom right, considering top and left neighbours
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 0) {
                    ret[i][j] = 0;
                    continue;
                }

                int lowest_neighbour = numeric_limits<int>::max();
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    lowest_neighbour = ret[i][j - 1];
                } else if (j == 0) {
                    lowest_neighbour = ret[i - 1][j];
                } else {
                    lowest_neighbour = min(ret[i][j - 1], ret[i - 1][j]);
                }

                ret[i][j] = lowest_neighbour + 1;
            }
        }
        // Secondly from bottom right to top left, considering bottom and right neighbours
        for (int i = mat.size() - 1; i >= 0; --i) {
            for (int j = mat[0].size() - 1; j >= 0; --j) {
                if (mat[i][j] == 0) {
                    ret[i][j] = 0;
                    continue;
                }

                int lowest_neighbour = numeric_limits<int>::max();
                if (i == mat.size() - 1 && j == mat[0].size() - 1) {
                    continue;
                } else if (i == mat.size() - 1) {
                    lowest_neighbour = ret[i][j + 1];
                } else if (j == mat[0].size() - 1) {
                    lowest_neighbour = ret[i + 1][j];
                } else {
                    lowest_neighbour = min(ret[i][j + 1], ret[i + 1][j]);
                }

                ret[i][j] = min(ret[i][j], lowest_neighbour + 1);
                // mat[i][j] = (i == 0 && j == 0) ? lowest_neighbour + 1 : min(mat[i][j], lowest_neighbour + 1);
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
    vector<vector<int>> mat;
    vector<vector<int>> ret;

    // [[0,0,0],[0,1,0],[1,2,1]]
    mat = {{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};
    ret = solution.updateMatrix(mat);
    for (auto& row : ret) {
        print_vector(row);
        cout << endl;
    }
    cout << endl;

    // [[0,0,0],[0,1,0],[1,2,1]]
    mat = {{0, 0, 0},
           {0, 1, 0},
           {1, 1, 1}};
    ret = solution.updateMatrix(mat);
    for (auto& row : ret) {
        print_vector(row);
        cout << endl;
    }
    cout << endl;
}
