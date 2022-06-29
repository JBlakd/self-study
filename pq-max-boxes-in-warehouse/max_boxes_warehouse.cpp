#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        // <warehouse_room_height, idx>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> warehouse_pq;
        for (int i = 0; i < warehouse.size(); ++i) {
            warehouse_pq.emplace(warehouse[i], i);
        }

        sort(boxes.begin(), boxes.end());

        int warehouse_idx = warehouse.size() - 1;
        int box_idx = 0;
        int ret = 0;
        while (box_idx < boxes.size()) {
            // calculate bottleneck
            while (!warehouse_pq.empty()) {
                if (warehouse_pq.top().second <= warehouse_idx) {
                    break;
                } else {
                    warehouse_pq.pop();
                }
            }

            if (warehouse_pq.empty()) {
                return ret;
            }

            const int& bottleneck = warehouse_pq.top().first;

            if (boxes[box_idx] <= bottleneck) {
                --warehouse_idx;
                ++box_idx;
                ++ret;
            } else {
                // current smallest box can't fit through the bottleneck
                // decrease warehouse_idx and recalculate bottleneck
                warehouse_idx = warehouse_pq.top().second - 1;
            }

            // current box can't fit through the bottleneck.
            // Continue this loop without advance the box to recalculate bottleneck
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
    vector<int> boxes;
    vector<int> warehouse;
    int output;

    boxes = {3};
    warehouse = {4, 2, 3, 4};
    output = solution.maxBoxesInWarehouse(boxes, warehouse);
    cout << output << '\n';
    assert(output == 1);

    boxes = {3};
    warehouse = {2, 2, 3, 4};
    output = solution.maxBoxesInWarehouse(boxes, warehouse);
    cout << output << '\n';
    assert(output == 0);

    boxes = {3, 1, 2, 4, 5, 6};
    warehouse = {2, 2};
    output = solution.maxBoxesInWarehouse(boxes, warehouse);
    cout << output << '\n';
    assert(output == 2);

    boxes = {1, 2, 3};
    warehouse = {1, 2, 3, 4};
    output = solution.maxBoxesInWarehouse(boxes, warehouse);
    cout << output << '\n';
    assert(output == 1);

    boxes = {1, 2, 2, 3, 4};
    warehouse = {3, 4, 1, 2};
    output = solution.maxBoxesInWarehouse(boxes, warehouse);
    cout << output << '\n';
    assert(output == 3);

    boxes = {4, 3, 4, 1};
    warehouse = {5, 3, 3, 4, 1};
    output = solution.maxBoxesInWarehouse(boxes, warehouse);
    cout << output << '\n';
    assert(output == 3);

    cout << "Great success!" << '\n';
}
