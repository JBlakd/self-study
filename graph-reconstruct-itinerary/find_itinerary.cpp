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
        // Return until we reach a node that still has outbound tickets.
        // As we're returning, push_front the current node to the itinerary
        // That's it brah

        // TODO
        return nullptr;
    }

   private:
    void visit(string airport) {
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
