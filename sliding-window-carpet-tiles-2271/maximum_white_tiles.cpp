#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        vector<bool> tile_vec(tiles.back().back(), false);
        for (auto &tile_block : tiles) {
            for (int i = tile_block[0] - 1; i <= tile_block[1] - 1; ++i) {
                tile_vec[i] = true;
            }
        }

        // sliding window
        int window_start = 0;
        int window_end = carpetLen - 1;
        // initialise sliding window
        int most_tiles_found = 0;
        for (int i = 0; i <= window_end; ++i) {
            if (tile_vec[i]) {
                ++most_tiles_found;
            }
        }

        // CAREFUL, THE TILES ARE ONE-INDEXED

        // slide the window
        int cur_tiles_in_window = most_tiles_found;
        while (window_end <= tiles.back().back() - 1) {
            ++window_start;
            ++window_end;

            // logic for updating cur_tiles_in_window
            // snake eating
            if (tile_vec[window_end]) {
                ++cur_tiles_in_window;
            }
            // snake shitting
            if (tile_vec[window_start - 1]) {
                --cur_tiles_in_window;
            }

            // brute force:
            // for (int i = window_start; i <= window_end; ++i) {
            //     if (tile_vec[i]) {
            //         ++cur_tiles_in_window;
            //     }
            // }

            // cout << "window_start: " << window_start << " window_end: " << window_end << " tiles: " << cur_tiles_in_window << endl;

            if (cur_tiles_in_window > most_tiles_found) {
                most_tiles_found = cur_tiles_in_window;
            }

            // Another case to save time
            if (cur_tiles_in_window == carpetLen) {
                return carpetLen;
            }
        }

        return most_tiles_found;
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
    vector<vector<int>> tiles;
    int carpetLen;

    // ?
    tiles = {{8051, 8057}, {8074, 8089}, {7994, 7995}, {7969, 7987}, {8013, 8020}, {8123, 8139}, {7930, 7950}, {8096, 8104}, {7917, 7925}, {8027, 8035}, {8003, 8011}};
    carpetLen = 9854;
    cout << solution.maximumWhiteTiles(tiles, carpetLen) << endl;

    // 9
    tiles = {{30, 32}, {20, 25}, {12, 18}, {1, 5}, {10, 11}};
    carpetLen = 10;
    cout << solution.maximumWhiteTiles(tiles, carpetLen) << endl;

    // 2
    tiles = {{1, 1}, {10, 11}};
    carpetLen = 2;
    cout << solution.maximumWhiteTiles(tiles, carpetLen) << endl;
}
