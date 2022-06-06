#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // unordered_set<string> name_set;
        // for (auto& account : accounts) {
        //     name_set.insert(account[0]);
        // }

        unordered_map<string, vector<string>> adj_map;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                for (int j = 1; j < account.size(); ++j) {
                    if (i == j) {
                        continue;
                    }

                    if (adj_map.find(account[i]) == adj_map.end()) {
                        adj_map[account[i]] = {account[j]};
                    } else {
                        adj_map[account[i]].push_back(account[j]);
                    }
                }
            }
        }

        unordered_set<string> outputted_emails;
        vector<vector<string>> output;
        for (auto& account : accounts) {
            if (outputted_emails.find(account[1]) != outputted_emails.end()) {
                continue;
            }

            output.emplace_back(initializer_list<string>{account[0]});
            dfs(account[1], output.back(), adj_map, outputted_emails);
            sort(output.back().begin() + 1, output.back().end());
        }

        return output;
    }

   private:
    void dfs(string& cur_node, vector<string>& dest_list, unordered_map<string, vector<string>>& adj_map, unordered_set<string>& outputted_emails) {
        outputted_emails.emplace(cur_node);
        dest_list.emplace_back(cur_node);
        for (auto& nei : adj_map[cur_node]) {
            if (outputted_emails.find(nei) == outputted_emails.end()) {
                // Only explore not-yet-outputted emails
                dfs(nei, dest_list, adj_map, outputted_emails);
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
    vector<vector<string>> accounts;
    vector<vector<string>> output;

    accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}};
    output = solution.accountsMerge(accounts);
    for (auto& merged_account : output) {
        print_vector(merged_account);
        cout << '\n';
    }
    cout << '\n';

    accounts = {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"}, {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"}, {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"}, {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"}, {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};
    output = solution.accountsMerge(accounts);
    for (auto& merged_account : output) {
        print_vector(merged_account);
        cout << '\n';
    }
    cout << '\n';
}
