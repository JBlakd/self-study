#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string alienOrder(vector<string>& words) {
        // construct directed graph
        unordered_map<char, vector<char>> adj_list;
        vector<string> group(words.size(), "$");

        // compare words belonging to the same group
        // get length of longest word
        int longest_word_len = 0;
        for (string& word : words) {
            longest_word_len = max(longest_word_len, (int)word.length());
        }

        // process first word because subsequent loop starts at 1
        for (char c : words[0]) {
            adj_list[c] = {};
        }

        int idx = 0;
        while (idx < longest_word_len) {
            for (int i = 1; i < words.size(); ++i) {
                // may as well use this loop to add letter to the hashmap, it doesn't have to connect to anything
                if (idx < words[i].length() && adj_list.find(words[i][idx]) == adj_list.end()) {
                    adj_list[words[i][idx]] = {};
                }

                // same group, but word[i] ran out of letters whereas word[i-1] has not
                if (group[i - 1] == group[i] && idx >= words[i].length() && idx < words[i - 1].length()) {
                    return "";
                }

                if (idx >= words[i - 1].length() || idx >= words[i].length()) {
                    continue;
                }

                // same group and different letters
                if (group[i - 1] == group[i] && words[i - 1][idx] != words[i][idx]) {
                    // add edge
                    adj_list[words[i - 1][idx]].emplace_back(words[i][idx]);
                }
            }

            ++idx;

            // second phase, re-group
            for (int i = 0; i < words.size(); ++i) {
                if (idx - 1 >= words[i].length()) {
                    group[i] = "$";
                } else {
                    group[i].push_back(words[i][idx - 1]);
                }
            }
        }

        // topological sort. Attempt Kahn's algorithm.
        // If no more indegree zero nodes, but still some nodes unaccounted for, then cycle detected and return ""
        // otherwise, return the topological order

        // construct in_degrees list
        unordered_map<char, int> in_degrees;
        for (auto& [node, nei_vec] : adj_list) {
            if (in_degrees.find(node) == in_degrees.end()) {
                in_degrees[node] = 0;
            }

            for (auto& nei : nei_vec) {
                ++in_degrees[nei];
            }
        }

        // Enqueue all nodes with zero indegree
        // Dequeue, and remove dequeued node from graph. Make sure to update in_degree and adj_list
        // Repeat until all graph nodes are removed. If successful, then a topological ordering has been generated.
        // If queue is empty but some graph nodes still remain, those nodes are in a cycle so there is no topological ordering
        queue<char> todo;
        for (auto& [node, in_degree] : in_degrees) {
            if (in_degree == 0) {
                todo.emplace(node);
            }
        }

        string ret = "";

        while (!todo.empty()) {
            char cur_node = todo.front();
            todo.pop();
            ret.push_back(cur_node);

            for (auto it = adj_list[cur_node].begin(); it != adj_list[cur_node].end();) {
                auto adjacent = *it;
                --in_degrees[adjacent];
                adj_list[cur_node].erase(it);
                if (in_degrees[adjacent] == 0) {
                    todo.push(adjacent);
                }
            }
        }

        for (auto& [node, in_degree] : in_degrees) {
            if (in_degree != 0) {
                return "";
            }
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
    vector<string> words;
    string output;

    words = {"wrt", "wrf", "er", "ett", "rftt"};
    output = solution.alienOrder(words);
    cout << output << '\n';
    assert((output == "wertf"));

    words = {"abc", "ab"};
    output = solution.alienOrder(words);
    cout << output << '\n';
    assert((output == ""));

    cout << "Great success!" << '\n';
}
