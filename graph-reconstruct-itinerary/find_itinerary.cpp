#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adj_list.clear();

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

        vector<string> itinerary;
        itinerary.push_back(string("JFK"));
        int tickets_remaining = tickets.size();
        dfs("JFK", tickets_remaining, itinerary);
        return itinerary;
    }

   private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj_list;
    
    void dfs(string cur_location, int& tickets_remaining, vector<string>& itinerary) {
        if (tickets_remaining == 0) {
            return;
        }
        // Copy the adj list into the current scope
        auto temp_adj = adj_list.at(cur_location);
        while (!temp_adj.empty()) {
            string next_location = temp_adj.top();
            temp_adj.pop();
            itinerary.push_back(next_location);
            --tickets_remaining;
            dfs(next_location, tickets_remaining, itinerary);
            if (tickets_remaining == 0) {
                // found a solution
                return;
            }
            // If we're here that means we're stuck
            // refund ticket, revert itinerary
            temp_adj.push(next_location);
            ++tickets_remaining;
            itinerary.pop_back();
        }
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
