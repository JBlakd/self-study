#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Mayber I don't need to sanitise expressions. Quit overthinking shit.
        // sanitise_expressions(equations);
        // sanitise_expressions(queries);

        // Now we are working with one-variable numerators and denominators

        //                             <neighbour, weight>
        unordered_map<string, vector<pair<string, double>>> adj_list;

        for (int i = 0; i < equations.size(); i++) {
            auto equation = equations[i];
            // Do the forward edge
            if (adj_list.find(equation[0]) == adj_list.end()) {
                // If adj_list for this numerator doesn't yet exist
                // Make the vector
                vector<pair<string, double>> temp = {make_pair(equation[1], values[i])};
                adj_list.insert(make_pair(equation[0], temp));
            } else {
                // Else add entry
                adj_list.at(equation[0]).push_back(make_pair(equation[1], values[i]));
            }

            // Do the reverse edge
            if (adj_list.find(equation[1]) == adj_list.end()) {
                // If adj_list for this numerator doesn't yet exist
                // Make the vector
                vector<pair<string, double>> temp = {make_pair(equation[0], 1 / values[i])};
                adj_list.insert(make_pair(equation[1], temp));
            } else {
                // Else add entry
                adj_list.at(equation[1]).push_back(make_pair(equation[0], 1 / values[i]));
            }
        }

        vector<double> output(queries.size());

        // Compute queries
        for (int query_idx = 0; query_idx < queries.size(); ++query_idx) {
            // check query validity
            if (adj_list.find(queries[query_idx][0]) == adj_list.end() || adj_list.find(queries[query_idx][1]) == adj_list.end()) {
                output[query_idx] = -1.0;
                continue;
            }

            // special cases
            if (queries[query_idx][0] == queries[query_idx][1]) {
                // if exists in adj list
                if (adj_list.find(queries[query_idx][0]) != adj_list.end()) {
                    output[query_idx] = 1.0;
                } else {
                    output[query_idx] = -1.0;
                }
                continue;
            }

            unordered_set<string> discovered;
            double total = 1.0;
            dfs(queries[query_idx][0], queries[query_idx], discovered, adj_list, total, &(output[query_idx]));
            if (output[query_idx] == 0.0) {
                output[query_idx] = -1.0;
            }
        }

        return output;
    }

   private:
    void dfs(string cur_node, vector<string>& query, unordered_set<string>& discovered,
             unordered_map<string, vector<pair<string, double>>>& adj_list, double total, double* output_location) {
        discovered.insert(cur_node);
        if (cur_node == query[1]) {
            // This is why we need output_location
            // the total variable is only guaranteed to have the correct value at the time of finding the destination, therefore we must store it
            // the total variable could be messed up by further DFS calls
            *(output_location) = total;
            return;
        }

        // Backup total variable
        double this_node_original_total = total;

        for (auto neighbour : adj_list.at(cur_node)) {
            // if neighbour is not yet discovered
            if (discovered.find(neighbour.first) == discovered.end()) {
                total = this_node_original_total;
                total *= neighbour.second;
                dfs(neighbour.first, query, discovered, adj_list, total, output_location);
            }
        }
        // didn't find anything
        // total = 1.0;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> equations;
    vector<double> values;
    vector<vector<string>> queries;
    vector<double> outputs;

    equations = {{"x1", "x2"}, {"x2", "x3"}, {"x1", "x4"}, {"x2", "x5"}};
    values = {3.0, 0.5, 3.4, 5.6};
    queries = {{"x2", "x4"}, {"x1", "x5"}, {"x1", "x3"}, {"x5", "x5"}, {"x5", "x1"}, {"x3", "x4"}, {"x4", "x3"}, {"x6", "x6"}, {"x0", "x0"}};
    outputs = solution.calcEquation(equations, values, queries);
    for (auto output : outputs) {
        cout << output << ", ";
    }
    cout << endl;

    equations = {{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
    values = {3.0, 4.0, 5.0, 6.0};
    queries = {{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"}, {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}};
    // queries = {{"x2", "x4"}};
    outputs = solution.calcEquation(equations, values, queries);
    for (auto output : outputs) {
        cout << output << ", ";
    }
    cout << endl;

    equations = {{"a", "b"}};
    values = {{0.5}};
    queries = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
    outputs = solution.calcEquation(equations, values, queries);
    for (auto output : outputs) {
        cout << output << ", ";
    }
    cout << endl;

    equations = {{"a", "b"}, {"b", "c"}};
    values = {2.0, 3.0};
    queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    outputs = solution.calcEquation(equations, values, queries);
    for (auto output : outputs) {
        cout << output << ", ";
    }
    cout << endl;

    equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    values = {1.5, 2.5, 5.0};
    queries = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    outputs = solution.calcEquation(equations, values, queries);
    for (auto output : outputs) {
        cout << output << ", ";
    }
    cout << endl;
}
