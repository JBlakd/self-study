#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class WordFilter {
   public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        class_words = &words;

        for (int i = 0; i < words.size(); ++i) {
            TrieNode* cur_node = root;
            for (char& c : words[i]) {
                if (cur_node->children[c - 'a'] == nullptr) {
                    cur_node->children[c - 'a'] = new TrieNode(c, -1);
                }
                cur_node = cur_node->children[c - 'a'];
            }
            cur_node->index = i;
        }
    }

    int f(string prefix, string suffix) {
        TrieNode* cur_node = root;
        for (char& c : prefix) {
            if (cur_node->children[c - 'a'] == nullptr) {
                return -1;
            }
            cur_node = cur_node->children[c - 'a'];
        }

        // dfs for suffix using
        priority_queue<int> possibilities;
        dfs(cur_node, suffix.back(), possibilities);

        while (!possibilities.empty()) {
            int cur_index = possibilities.top();
            string& cur_word = class_words->at(cur_index);
            possibilities.pop();

            if (suffix.length() > cur_word.length()) {
                continue;
            }

            // check if cur_word has a valid suffix
            int suffix_i = suffix.length() - 1;
            int cur_word_i = cur_word.length() - 1;
            while (suffix_i >= 0 && cur_word_i >= 0) {
                if (suffix[suffix_i] != cur_word[cur_word_i]) {
                    // break to move on to next word;
                    break;
                }
                --suffix_i;
                --cur_word_i;
            }
            if (suffix_i == -1) {
                // valid word found
                return cur_index;
            }
        }

        return -1;
    }

   private:
    class TrieNode {
       public:
        char val;
        TrieNode* children[26] = {nullptr};
        // -1 denotes index does not exist
        int index = -1;

        TrieNode() : val('.') {
        }

        TrieNode(char c, int i) : val(c), index(i) {
        }

        ~TrieNode() {
            for (TrieNode* child : children) {
                delete child;
            }
        }
    };

    TrieNode* root = nullptr;
    vector<string>* class_words = nullptr;

    void dfs(TrieNode* cur_node, char& last_letter, priority_queue<int>& possibilities) {
        if (cur_node->index != -1 && cur_node->val == last_letter) {
            possibilities.emplace(cur_node->index);
        }

        for (TrieNode* child : cur_node->children) {
            if (child != nullptr) {
                dfs(child, last_letter, possibilities);
            }
        }
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

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
    vector<string> words;

    words = {"apple"};
    {
        WordFilter solution(words);
        assert(solution.f("a", "a") == -1);
    }

    words = {"ape", "apple", "apellate"};
    {
        WordFilter solution(words);
        assert(solution.f("ap", "le") == 1);
        assert(solution.f("ap", "e") == 2);
        assert(solution.f("app", "e") == 1);
        assert(solution.f("a", "pe") == 0);
        assert(solution.f("ap", "pe") == 0);
    }

    cout << "Great success!" << '\n';
}
