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

        int max_tiles_covered = 0;

        // Now we have a sorted array of tile intervals
        // Try to overlay the carpet at the start of every interval
        for (int i = 0; i < tiles.size(); ++i) {
            // return carpet length if tile interval longer than the carpet is encountered
            if (tiles[i][1] - tiles[i][0] + 1 > carpetLen) {
                return carpetLen;
            }

            // find the last tile interval that this carpet is involved in
            // this tile interval may or may be fully encompassed by the carpet
            int carpet_end = tiles[i][0] + carpetLen - 1;
            int end_tile_interval_index = i;
            for (int j = i; j < tiles.size(); ++j) {
                if (tiles[j][0] <= carpet_end) {
                    end_tile_interval_index = j;
                } else {
                    break;
                }
            }

            // sum up the tiles of all the tile intervals that the carpet is involved in
            int cur_tiles_covered = 0;
            for (int j = i; j <= end_tile_interval_index; j++) {
                if (j == end_tile_interval_index) {
                    // if the end tile interval is not fully encompassed by the carpet
                    if (tiles[j][1] > carpet_end) {
                        cur_tiles_covered += (carpet_end - tiles[j][0] + 1);
                    } else {
                        // Otherwise, just like normal.
                        cur_tiles_covered += (tiles[j][1] - tiles[j][0] + 1);
                    }
                } else {
                    cur_tiles_covered += (tiles[j][1] - tiles[j][0] + 1);
                }
            }

            if (cur_tiles_covered > max_tiles_covered) {
                max_tiles_covered = cur_tiles_covered;
            }
        }

        return max_tiles_covered;
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

    // 1281 ?
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
