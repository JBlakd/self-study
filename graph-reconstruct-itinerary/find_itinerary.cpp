#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> targets;
        vector<string> route;

        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit("JFK", targets, route);
        return vector<string>(route.rbegin(), route.rend());
    }

   private:
    void visit(string airport, unordered_map<string, multiset<string>>& targets, vector<string>& route) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next, targets, route);
        }
        route.push_back(airport);
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
