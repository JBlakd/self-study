#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int ret = 0;
        int char_map[26] = {0};

        // count characters
        for (char c : tasks) {
            ++char_map[c - 'A'];
        }

        // Enqueue characters into pq in descending frequency
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (char_map[i] != 0) {
                pq.emplace(char_map[i], i + 'A');
            }
        }

        //    <count, char, cooled_time>
        queue<tuple<int, char, int>> cooldown;

        while (!pq.empty() || !cooldown.empty()) {
            if (!pq.empty()) {
                if (pq.top().first > 1) {
                    cooldown.emplace(pq.top().first - 1, pq.top().second, ret + n);
                }
                pq.pop();
            }

            if (!cooldown.empty()) {
                auto& [count, c, cooled_time] = cooldown.front();
                if (ret >= cooled_time) {
                    pq.emplace(count, c);
                    cooldown.pop();
                }
            }

            ++ret;
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
    vector<char> tasks;
    int n;

    // 1
    tasks = {'Z'};
    n = 0;
    cout << solution.leastInterval(tasks, n) << '\n';

    // 1
    tasks = {'Z'};
    n = 100;
    cout << solution.leastInterval(tasks, n) << '\n';

    // 16
    tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    n = 2;
    cout << solution.leastInterval(tasks, n) << '\n';

    // 6
    tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    n = 0;
    cout << solution.leastInterval(tasks, n) << '\n';

    // 8
    tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    n = 2;
    cout << solution.leastInterval(tasks, n) << '\n';
}
