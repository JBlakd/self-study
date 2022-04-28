#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
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

        // TODO https://leetcode.com/problems/reconstruct-itinerary/discuss/78799/Very-Straightforward-DFS-Solution-with-Detailed-Explanations

        return itinerary;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> tickets;
    vector<string> output;

    tickets = {{"JFK, KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
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
