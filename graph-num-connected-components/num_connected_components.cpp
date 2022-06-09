#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // parse edges into adj list
        vector<vector<int>> adj_list(n);
        for (auto& edge : edges) {
            adj_list[edge[0]].emplace_back(edge[1]);
            adj_list[edge[1]].emplace_back(edge[0]);
        }

        vector<bool> visited(n);
        int ret = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ret;
                dfs(i, visited, adj_list);
            }
        }

        return ret;
    }

   private:
    void dfs(int cur_node, vector<bool>& visited, vector<vector<int>>& adj_list) {
        visited[cur_node] = true;
        for (auto& nei : adj_list[cur_node]) {
            if (!visited[nei]) {
                dfs(nei, visited, adj_list);
            }
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
}
