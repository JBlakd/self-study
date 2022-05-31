#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> already_used(rows, vector<bool>(cols, false));

        // Start dfs from first letter of word
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word, already_used)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

   private:
    int rows;
    int cols;
    const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(int cur_row, int cur_col, int cur_idx, vector<vector<char>>& board, string& word, vector<vector<bool>>& already_used) {
        if (cur_idx == word.length() - 1) {
            return true;
        }

        already_used[cur_row][cur_col] = true;

        for (auto& [row_change, col_change] : dirs) {
            int nei_row = cur_row + row_change;
            int nei_col = cur_col + col_change;
            // reject invalid
            if (nei_row < 0 || nei_col < 0 || nei_row >= rows || nei_col >= cols || board[nei_row][nei_col] != word.at(cur_idx + 1) || already_used[nei_row][nei_col]) {
                continue;
            }

            if (dfs(nei_row, nei_col, cur_idx + 1, board, word, already_used)) {
                return true;
            }
        }

        // Backtrack
        already_used[cur_row][cur_col] = false;
        // When we have not reached the last character, and yet there are no valid neighbours to explore. Return false for this DFS
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
    vector<vector<char>> board;
    string word;

    // 1
    board = {{'C', 'A', 'A'},
             {'A', 'A', 'A'},
             {'B', 'C', 'F'}};
    word = "AAB";
    cout << solution.exist(board, word) << endl;

    // 0
    board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    word = "ABCB";
    cout << solution.exist(board, word) << endl;

    // 1
    board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    word = "ABCCED";
    cout << solution.exist(board, word) << endl;

    // 1
    board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    word = "SEE";
    cout << solution.exist(board, word) << endl;
}
