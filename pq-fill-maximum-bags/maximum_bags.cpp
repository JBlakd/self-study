#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // <number of rocks required to be filled, index>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int num_filled_bags = 0;
        int num_rocks_remaining = additionalRocks;

        // Loop through the bags and populate the unfilled ones into the queue
        for (int i = 0; i < capacity.size(); ++i) {
            if (capacity[i] == rocks[i]) {
                ++num_filled_bags;
            } else {
                pq.emplace(capacity[i] - rocks[i], i);
            }
        }

        // This loop will break when num_rocks_remaining or when pq becomes empty
        while (num_rocks_remaining > 0 && !pq.empty()) {
            if (num_rocks_remaining >= pq.top().first) {
                ++num_filled_bags;
                num_rocks_remaining -= pq.top().first;
                pq.pop();
            } else {
                break;
            }
        }

        return num_filled_bags;
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
    vector<int> capacity;
    vector<int> rocks;
    int additionalRocks;
    //                                          1
    capacity = {54, 18, 91, 49, 51, 45, 58, 54, 47, 91, 90, 20, 85, 20, 90, 49, 10, 84, 59, 29, 40, 9, 100, 1, 64, 71, 30, 46, 91};
    rocks = {14, 13, 16, 44, 8, 20, 51, 15, 46, 76, 51, 20, 77, 13, 14, 35, 6, 34, 34, 13, 3, 8, 1, 1, 61, 5, 2, 15, 18};
    additionalRocks = 77;
    cout << solution.maximumBags(capacity, rocks, additionalRocks) << endl;

    capacity = {2, 3, 4, 5};
    rocks = {1, 2, 4, 4};
    additionalRocks = 2;
    cout << solution.maximumBags(capacity, rocks, additionalRocks) << endl;

    capacity = {10, 2, 2};
    rocks = {2, 2, 0};
    additionalRocks = 100;
    cout << solution.maximumBags(capacity, rocks, additionalRocks) << endl;
}
