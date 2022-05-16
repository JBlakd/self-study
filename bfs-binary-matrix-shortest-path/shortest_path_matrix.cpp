#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> todo;
        todo.emplace(0, 0);
        grid[0][0] = 1;
        int path_length = 1;
        //                              b-r     b       b-l      l        t-l       t        t-r      r
        vector<pair<int, int>> dirs = {{1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}};

        while (!todo.empty()) {
            int current_level_contains = todo.size();

            while (current_level_contains != 0) {
                pair<int, int> cur_node = todo.front();
                todo.pop();
                --current_level_contains;
                if (cur_node.first == n - 1 && cur_node.second == n - 1) {
                    return path_length;
                }

                // calculate neighbours
                for (auto dir : dirs) {
                    // eliminate invalid neighbours
                    pair<int, int> neighbour = make_pair(cur_node.first + dir.first, cur_node.second + dir.second);
                    if (neighbour.first < 0 || neighbour.second < 0 || neighbour.first >= n || neighbour.second >= n || grid[neighbour.first][neighbour.second] == 1) {
                        continue;
                    }
                    // Mark valid neighbour as explored
                    grid[neighbour.first][neighbour.second] = 1;
                    todo.push(neighbour);
                }
            }
            // Increment depth after completing all nodes at the current depth
            ++path_length;
        }

        return -1;
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
    vector<vector<int>> grid;

    grid = {{1}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    grid = {{0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    grid = {{0, 0, 0},
            {1, 1, 0},
            {1, 1, 0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    grid = {{0, 1},
            {1, 0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;
}
