#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }

        int rows = image.size();
        int cols = image[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int orig_color = image[sr][sc];
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        image[sr][sc] = newColor;

        while (!q.empty()) {
            auto& [cur_row, cur_col] = q.front();
            q.pop();

            for (auto& [dx, dy] : dirs) {
                int nei_row = cur_row + dx;
                int nei_col = cur_col + dy;

                if (nei_row < 0 || nei_col < 0 || nei_row >= rows || nei_col >= cols || image[nei_row][nei_col] != orig_color) {
                    continue;
                }

                image[nei_row][nei_col] = newColor;
                q.emplace(nei_row, nei_col);
            }
        }

        return image;
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
    vector<vector<int>> image;
    int sr;
    int sc;
    int newColor;

    image = {{1, 1, 1},
             {1, 1, 0},
             {1, 0, 1}};
    sr = 1;
    sc = 1;
    newColor = 2;
    solution.floodFill(image, sr, sc, newColor);
    for (auto& row : image) {
        print_vector(row);
        cout << '\n';
    }
    cout << '\n';
    solution.floodFill(image, 1, 2, 2);
    for (auto& row : image) {
        print_vector(row);
        cout << '\n';
    }
    cout << '\n';
    solution.floodFill(image, 0, 0, 7);
    for (auto& row : image) {
        print_vector(row);
        cout << '\n';
    }
    cout << '\n';
    solution.floodFill(image, 0, 0, 7);
    for (auto& row : image) {
        print_vector(row);
        cout << '\n';
    }
    cout << '\n';
}
