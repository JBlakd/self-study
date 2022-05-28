#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // calculate degrees
        // index denotes city, degrees[index] denotes degree
        vector<int> degree(n, 0);
        for (auto& road : roads) {
            ++degree[road[0]];
            ++degree[road[1]];
        }

        //             pair<degree, city>
        priority_queue<pair<int, int>> most_connected_cities;
        for (int i = 0; i < degree.size(); ++i) {
            most_connected_cities.emplace(degree[i], i);
        }

        // Use the priority queue to assign importance
        // Index denotes city, value denotes importance
        vector<int> importance(n, 0);
        while (!most_connected_cities.empty()) {
            importance[most_connected_cities.top().second] = most_connected_cities.size();
            most_connected_cities.pop();
        }

        // Calculate total importance
        long long ret = 0;
        for (auto& road : roads) {
            ret += importance[road[0]];
            ret += importance[road[1]];
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
    int n;
    vector<vector<int>> roads;

    // 43
    n = 5;
    roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    cout << solution.maximumImportance(n, roads) << endl;

    // 20
    n = 5;
    roads = {{0, 3}, {2, 4}, {1, 3}};
    cout << solution.maximumImportance(n, roads) << endl;
}
