#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        // ONLY START EXPLORING FROM EDGE 'O' SQUARES
        // ANYTHING REACHABLE FROM THESE SAFE ORIGINS IS CONSIDERED SAFE

        for (int col = 0; col < cols; ++col) {
            if (board[0][col] == 'O') {
                solve_helper(0, col, board);
            }
            if (board[rows - 1][col] == 'O') {
                solve_helper(rows - 1, col, board);
            }
        }
        for (int row = 1; row < rows - 1; ++row) {
            if (board[row][0] == 'O') {
                solve_helper(row, 0, board);
            }
            if (board[row][cols - 1] == 'O') {
                solve_helper(row, cols - 1, board);
            }
        }

        // AT THIS POINT, ANYTHING NOT MARKED AS SAFE IS CONSIDERED 'X'
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] != 'S') {
                    board[row][col] = 'X';
                } else {
                    // RESTORE SAFE SQUARES BACK TO 'O' SQUARES
                    board[row][col] = 'O';
                }
            }
        }
    }

   private:
    int rows;
    int cols;

    void solve_helper(int row, int col, vector<vector<char>>& board) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[row][col] = true;
        // MARK AS SAFE
        board[row][col] = 'S';
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            // NOTE THAT cur_node should already be explored
            pair<int, int> cur_node = q.front();
            q.pop();

            for (auto direction : directions) {
                pair<int, int> neighbour = make_pair(cur_node.first + direction[0], cur_node.second + direction[1]);
                // Reject out of bound neighbours
                if (neighbour.first < 0 || neighbour.first >= rows || neighbour.second < 0 || neighbour.second >= cols) {
                    continue;
                }

                // Only accept 'O' neighbours && unvisited
                if (!visited[neighbour.first][neighbour.second] && board[neighbour.first][neighbour.second] == 'O') {
                    // Explore here and here only!!!
                    visited[neighbour.first][neighbour.second] = true;
                    board[neighbour.first][neighbour.second] = 'S';
                    q.push(neighbour);
                }
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board;

    board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    solution.solve(board);
    cout << endl;
    for (auto row : board) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    board = {
        {'X', 'X', 'X', 'X'},
        {'O', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'X'}};
    cout << endl;
    solution.solve(board);
    for (auto row : board) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}
