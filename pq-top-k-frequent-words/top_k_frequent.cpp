#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashmap;
        for (auto& word : words) {
            ++hashmap[word];
        }

        // auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
        //     if (a.second == b.second) {
        //         return lexicographical_compare(a.first.begin(), a.first.end(), b.first.begin(), b.first.end());
        //     } else {
        //         return (a.second < b.second);
        //     }
        // };

        // priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        // for (const auto& entry : hashmap) {
        //     pq.emplace(entry);
        // }

        auto cmp = [](unordered_map<string, int>::iterator a, unordered_map<string, int>::iterator b) {
            if (a->second == b->second) {
                return !(lexicographical_compare(a->first.begin(), a->first.end(), b->first.begin(), b->first.end()));
            } else {
                return (a->second < b->second);
            }
        };

        priority_queue<unordered_map<string, int>::iterator, vector<unordered_map<string, int>::iterator>, decltype(cmp)> pq(cmp);
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            pq.emplace(it);
        }

        vector<string> ret(k);
        for (int i = 0; i < k; ++i) {
            ret[i] = pq.top()->first;
            pq.pop();
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
    int k;

    // i love
    words = {"i", "love", "leetcode", "i", "love", "coding"};
    k = 2;
    print_vector(solution.topKFrequent(words, k));
    cout << '\n';

    // the is sunny day
    words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    k = 4;
    print_vector(solution.topKFrequent(words, k));
    cout << '\n';
}
