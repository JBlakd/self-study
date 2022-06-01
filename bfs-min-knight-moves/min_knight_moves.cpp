#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);

        //    tuple<row, col, steps>
        queue<tuple<int, int, int>> todo;
        unordered_set<string> visited;
        visited.insert("0,0");
        todo.emplace(0, 0, 0);

        while (!todo.empty()) {
            auto [row, col, steps] = todo.front();
            todo.pop();

            if (row == x && col == y) {
                return steps;
            }

            // Critical optimisation: don't explore the other 3 quadrants beyond the first two rows/cols
            if (row < -2 || col < -2) {
                continue;
            }
            // Critical optimisation: don't explore beyond the first two rows/cols of the answer
            if (row > x + 2 || col > y + 2) {
                continue;
            }

            for (auto& [dx, dy] : dirs) {
                int nei_row = row + dx;
                int nei_col = col + dy;
                string nei_str = to_string(nei_row).append(",").append(to_string(nei_col));

                if (visited.find(nei_str) != visited.end()) {
                    continue;
                }

                todo.emplace(nei_row, nei_col, steps + 1);
                visited.insert(nei_str);
            }
        }

        // should never be here
        return -1;
    }

   private:
    vector<pair<int, int>> dirs = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
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
    int x, y;

    // 72
    x = 130;
    y = -86;
    cout << solution.minKnightMoves(x, y) << endl;

    // 2
    x = 1;
    y = 1;
    cout << solution.minKnightMoves(x, y) << endl;

    // 4
    x = 5;
    y = 5;
    cout << solution.minKnightMoves(x, y) << endl;
}
