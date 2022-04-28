#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj_list;

        // Parse ticket vector into adj_list
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

        // TODO have to use a queue otherwise could end up in a location with no ticket out,
        // while still having other tickets in your wallet
        // Actually no need to have a queue as long as you ensure the priority queue in the adjacency list is working properly
        // Because the question always guarantees working input
        // Well actually working input doesn't guarantee that you won't be stranded, so you need a queue after all
        // i.e. testcase  {{"JFK, KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}}

        vector<string> itinerary;
        int tickets_left = tickets.size();
        string cur_location = "JFK";
        itinerary.push_back("JFK");

        while (tickets_left > 0) {
            // Fly to a connection with highest alphabetical order from cur_location
            string next_location = adj_list.at(cur_location).top();
            adj_list.at(cur_location).pop();

            // They take your ticket
            --tickets_left;

            // You've arrived!
            cur_location = next_location;
            itinerary.push_back(cur_location);
        }

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
