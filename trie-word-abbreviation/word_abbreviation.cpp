#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        // Don't actually have to implement a trie for this,
        // but a trie was used to visualise the problem and to formulate a solution

        // Key: a string consisting of the first character of the word, then the last character of the word, then length of the word
        // Value: a vector of indices of the input vector representing all the words which fit the key criteria
        unordered_map<string, unordered_set<int>> hashmap;
        // Keys array so we don't have to recalculate the key
        vector<string> keys(words.size());

        for (int i = 0; i < words.size(); ++i) {
            string key(2, '$');
            key[0] = words[i][0];
            key[1] = words[i].back();
            key.append(to_string(words[i].length()));
            hashmap[key].emplace(i);
            keys[i] = key;
        }

        // unordered_set<string> exists;
        vector<string> ret(words.size(), "");

        // calculating each result of the return vector
        for (int i = 0; i < words.size(); ++i) {
            // already calculated
            if (ret[i].length() > 0) {
                continue;
            }

            // If no conflicts and the potential abbreviation actually abbreviates
            if (hashmap[keys[i]].size() == 1 && words[i].length() > 3) {
                ret[i].push_back(words[i][0]);
                ret[i].append(to_string(words[i].length() - 2));
                ret[i].push_back(words[i].back());
                continue;
            }

            // this word is too short to be abbreviates
            if (words[i].length() <= 3) {
                ret[i] = words[i];
                continue;
            }

            // we have encountered a word that can be abbreviated, but shares the same key with other words
            // let's make a trie with this set
            unordered_map<string, int> word_map;
            Node* root = new Node();
            for (auto& conflict_word_idx : hashmap[keys[i]]) {
                word_map[words[conflict_word_idx]] = conflict_word_idx;
                Node* cur_node = root;
                for (char& c : words[conflict_word_idx]) {
                    if (cur_node->children[c - 'a'] == nullptr) {
                        cur_node->children[c - 'a'] = new Node(c);
                        ++cur_node->num_children;
                    }
                    cur_node = cur_node->children[c - 'a'];
                }
                cur_node->is_word = true;
            }

            // dfs the trie, return until multi-child node reached, then populate the ret
            // only dfs if ret at current index is empty
            string cur_string = "";
            int active_idx = -1;
            dfs(root, cur_string, active_idx, words, word_map, ret);
        }

        return ret;
    }

   private:
    struct Node {
       public:
        char val;
        Node* children[26] = {nullptr};
        int num_children = 0;
        bool is_word;

        Node() : val('.'), is_word(false) {
        }

        Node(char c) : val(c), is_word(false) {
        }

        ~Node() {
            for (Node* child : children) {
                delete child;
            }
        }
    };

    void dfs(Node* cur_node, string& cur_string, int& active_idx, vector<string>& words, unordered_map<string, int>& word_map, vector<string>& ret) {
        if (cur_node->num_children == 0) {
            active_idx = word_map[cur_string];
            return;
        }

        for (Node*& child : cur_node->children) {
            if (child != nullptr) {
                cur_string.push_back(child->val);
                dfs(child, cur_string, active_idx, words, word_map, ret);
                cur_string.pop_back();

                if (active_idx != -1 && cur_node->num_children > 1) {
                    // we've returned to a multi-child node. populate ret
                    if ((words[active_idx].length() - 1) - (cur_string.length() + 1) >= 2) {
                        ret[active_idx] = words[active_idx].substr(0, cur_string.length() + 1);
                        ret[active_idx].append(to_string((words[active_idx].length() - 1) - (cur_string.length() + 1)));
                        ret[active_idx].push_back(words[active_idx].back());
                    } else {
                        ret[active_idx] = words[active_idx];
                    }
                    active_idx = -1;
                }
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
    vector<string> words;
    vector<string> expected;
    vector<string> output;

    words = {"intuits", "intercoms", "internets", "internbus"};
    output = solution.wordsAbbreviation(words);
    print_vector(output);
    cout << '\n';
    expected = {"i5s", "interc2s", "internets", "internbus"};
    for (int i = 0; i < output.size(); ++i) {
        assert(output[i] == expected[i]);
    }

    words = {"intuits", "intercoms", "internets"};
    output = solution.wordsAbbreviation(words);
    print_vector(output);
    cout << '\n';
    expected = {"i5s", "interc2s", "intern2s"};
    for (int i = 0; i < output.size(); ++i) {
        assert(output[i] == expected[i]);
    }

    words = {"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
    output = solution.wordsAbbreviation(words);
    print_vector(output);
    cout << '\n';
    expected = {"l2e", "god", "internal", "me", "i6t", "interval", "inte4n", "f2e", "intr4n"};
    for (int i = 0; i < output.size(); ++i) {
        assert(output[i] == expected[i]);
    }

    cout << "Great success!" << '\n';
}
