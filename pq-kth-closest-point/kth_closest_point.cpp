#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // As we are pushing the input points into the MAX pq, we only keep the top k points
        //                  <sqdist, x  , y  >
        priority_queue<tuple<double, int, int>> pq;
        for (auto point : points) {
            pq.push(make_tuple(point[0] * point[0] + point[1] * point[1], point[0], point[1]));
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Return the k-sized min PQ as a vector
        vector<vector<int>> ret;
        while (!pq.empty()) {
            ret.push_back({get<1>(pq.top()), get<2>(pq.top())});
            pq.pop();
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points;
    int k;
    vector<vector<int>> output;

    points = {{3, 3}, {5, -1}, {-2, 4}};
    k = 2;
    output = solution.kClosest(points, k);
}
