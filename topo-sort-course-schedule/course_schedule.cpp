#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Parse input data into indegree array and adj_list
        vector<int> in_degree(numCourses);
        vector<vector<int>> adj_list(numCourses);
        for (auto prerequisite : prerequisites) {
            ++in_degree[prerequisite[0]];
            adj_list[prerequisite[1]].push_back(prerequisite[0]);
        }

        // Kahn's algorithm
        // https://www.youtube.com/watch?v=cIBFEhD77b4
        //
        // Enqueue all nodes with zero indegree
        // Dequeue, and remove dequeued node from graph. Make sure to update in_degree and adj_list
        // Repeat until all graph nodes are removed. If successful, then a topological ordering has been generated.
        // If queue is empty but some graph nodes still remain, those nodes are in a cycle so there is no topological ordering

        queue<int> todo;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                todo.push(i);
            }
        }

        vector<int> topological_order;

        while (!todo.empty()) {
            int cur_node = todo.front();
            todo.pop();
            topological_order.push_back(cur_node);

            for (auto it = adj_list[cur_node].begin(); it != adj_list[cur_node].end();) {
                auto adjacent = *it;
                --in_degree[adjacent];
                adj_list[cur_node].erase(it);
                if (in_degree[adjacent] == 0) {
                    todo.push(adjacent);
                }
            }
        }

        if (topological_order.size() == numCourses) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution solution;
    int numCourses;
    vector<vector<int>> prerequisites;

    // true
    numCourses = 2;
    prerequisites = {{1, 0}};
    cout << (solution.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    // false
    numCourses = 2;
    prerequisites = {{1, 0}, {0, 1}};
    cout << (solution.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    // true
    numCourses = 4;
    prerequisites = {{1, 0}, {2, 0}, {3, 0}};
    cout << (solution.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    // false
    numCourses = 4;
    prerequisites = {{1, 0}, {2, 1}, {3, 2}, {0, 3}};
    cout << (solution.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
}
