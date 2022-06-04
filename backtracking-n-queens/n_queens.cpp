#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> solveNQueens(int dimension) {
        n = dimension;
        vector<vector<int>> num_disallows(n, vector<int>(n, 0));
        vector<vector<string>> ret;

        vector<string> cur_board(n, string(n, '.'));
        dfs(-1, 0, cur_board, ret, num_disallows);

        return ret;
    }

   private:
    int n;
    vector<pair<int, int>> diag_dirs = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

    void dfs(int cur_row, int cur_col, vector<string>& cur_board, vector<vector<string>>& ret, vector<vector<int>>& num_disallows) {
        // base case: final row reached
        if (cur_row == n - 1) {
            incr_disallows(cur_row, cur_col, num_disallows);
            cur_board[cur_row][cur_col] = 'Q';
            ret.push_back(cur_board);
            return;
        }

        // visit current position
        if (cur_row >= 0) {
            incr_disallows(cur_row, cur_col, num_disallows);
            cur_board[cur_row][cur_col] = 'Q';
        }

        // explore all columns in next row
        for (int i = 0; i < n; ++i) {
            if (num_disallows[cur_row + 1][i] > 0) {
                continue;
            }

            dfs(cur_row + 1, i, cur_board, ret, num_disallows);

            // backtrack
            decr_disallows(cur_row + 1, i, num_disallows);
            cur_board[cur_row + 1][i] = '.';
        }
    }

    void incr_disallows(int x, int y, vector<vector<int>>& num_disallows) {
        // current position
        ++num_disallows[x][y];
        // horizontal
        for (int i = 0; i < n; ++i) {
            if (i == y) continue;
            ++num_disallows[x][i];
        }
        // vertical
        for (int i = 0; i < n; ++i) {
            if (i == x) continue;
            ++num_disallows[i][y];
        }
        // diagonal
        int dist = 1;
        while (true) {
            bool valid_found = false;
            for (const auto& [dx, dy] : diag_dirs) {
                int nei_x = x + dist * dx;
                int nei_y = y + dist * dy;
                if (nei_x < 0 || nei_y < 0 || nei_x >= n || nei_y >= n) {
                    continue;
                }

                valid_found = true;
                ++num_disallows[nei_x][nei_y];
            }

            if (!valid_found) {
                break;
            }

            ++dist;
        }
    }

    void decr_disallows(int x, int y, vector<vector<int>>& num_disallows) {
        // current position
        --num_disallows[x][y];
        // horizontal
        for (int i = 0; i < n; ++i) {
            if (i == y) continue;
            --num_disallows[x][i];
        }
        // vertical
        for (int i = 0; i < n; ++i) {
            if (i == x) continue;
            --num_disallows[i][y];
        }
        // diagonal
        int dist = 1;
        while (true) {
            bool valid_found = false;
            for (const auto& [dx, dy] : diag_dirs) {
                int nei_x = x + dist * dx;
                int nei_y = y + dist * dy;
                if (nei_x < 0 || nei_y < 0 || nei_x >= n || nei_y >= n) {
                    continue;
                }

                valid_found = true;
                --num_disallows[nei_x][nei_y];
            }

            if (!valid_found) {
                break;
            }

            ++dist;
        }
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
    int n;
    vector<vector<string>> output;

    // 2
    n = 4;
    output = solution.solveNQueens(n);
    cout << output.size() << '\n';
}
