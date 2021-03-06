#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /**
         *
         *  Hierholzer's Algorithm
         *  https://www.youtube.com/watch?v=8MpoO2zA2l4
         *
         **/

        // DFS until we get stuck, spending tickets with every DFS
        // When we get stuck, return until we reach a node that still has outbound tickets. This is the magical ticket-free backtracking process
        // As we're returning, push_front the current node to the itinerary
        // That's it brah

        // Parse ticket vector into adj_list
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj_list;
        for (auto ticket : tickets) {
            string& src = ticket[0];
            string& dest = ticket[1];

            // If not in adj_list
            if (adj_list.find(src) == adj_list.end()) {
                // Use stack memory to optimise for speed
                priority_queue<string, vector<string>, greater<string>> temp_pq;
                temp_pq.push(dest);
                // New key entry in adj_list
                adj_list.insert(make_pair(src, temp_pq));
            } else {
                adj_list.at(src).push(dest);
            }
        }

        vector<string> itinerary;
        dfs("JFK", itinerary, adj_list);
        return vector<string>(itinerary.rbegin(), itinerary.rend());
    }

   private:
    void dfs(string cur_loc, vector<string>& itinerary, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj_list) {
        // Keep doing the DFS
        while (adj_list.find(cur_loc) != adj_list.end() && !adj_list.at(cur_loc).empty()) {
            // And spend those tickets!
            string next_loc = adj_list.at(cur_loc).top();
            adj_list.at(cur_loc).pop();
            dfs(next_loc, itinerary, adj_list);
        }
        // uh-oh we're stuck with no ticket back, time to magically backtrack
        itinerary.push_back(cur_loc);
    }
};

int main() {
    Solution solution;
    vector<vector<string>> tickets;
    vector<string> output;

    tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    output = solution.findItinerary(tickets);
    for (auto location : output) {
        cout << location << ", ";
    }
    cout << endl;

    tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    output = solution.findItinerary(tickets);
    for (auto location : output) {
        cout << location << ", ";
    }
    cout << endl;

    tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    output = solution.findItinerary(tickets);
    for (auto location : output) {
        cout << location << ", ";
    }
    cout << endl;
}
