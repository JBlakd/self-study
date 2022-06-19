#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Node();

        // Add all words to trie
        for (string& word : products) {
            Node* cur_node = root;
            for (char& c : word) {
                if (cur_node->children[c - 'a'] == nullptr) {
                    cur_node->children[c - 'a'] = new Node(c);
                }
                cur_node = cur_node->children[c - 'a'];
            }
            cur_node->is_word = true;
        }

        vector<vector<string>> ret(searchWord.length());
        Node* cur_node = root;
        string cur_string = "";
        // auto compare = [](string& a, string& b) { return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()); };
        for (int i = 0; i < searchWord.length(); ++i) {
            // check if trie node exists
            if (cur_node->children[searchWord[i] - 'a'] == nullptr) {
                return ret;
            }

            cur_node = cur_node->children[searchWord[i] - 'a'];
            cur_string.push_back(searchWord[i]);

            vector<string> found;
            // dfs to search for all words from cur_node
            dfs(cur_node, cur_string, found);

            sort(found.begin(), found.end());
            if (found.size() >= 3) {
                ret[i] = vector<string>(found.begin(), found.begin() + 3);
            } else {
                ret[i] = vector<string>(found.begin(), found.end());
            }
        }

        return ret;
    }

   private:
    struct Node {
       public:
        char val;
        Node* children[26] = {nullptr};
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

    Node* root = nullptr;

    void dfs(Node* cur_node, string& cur_string, vector<string>& found) {
        // visit
        if (cur_node->is_word) {
            found.emplace_back(cur_string);
        }

        // visit neighbours
        for (Node* child : cur_node->children) {
            if (child != nullptr) {
                cur_string.push_back(child->val);
                dfs(child, cur_string, found);
                cur_string.pop_back();
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
    vector<string> products;
    string searchWord;
    vector<vector<string>> output;

    products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    searchWord = "mouse";
    output = solution.suggestedProducts(products, searchWord);
    for (auto& results : output) {
        print_vector(results);
        cout << ", ";
    }
    cout << '\n';

    products = {"havana"};
    searchWord = "havana";
    output = solution.suggestedProducts(products, searchWord);
    for (auto& results : output) {
        print_vector(results);
        cout << ", ";
    }
    cout << '\n';

    products = {"bags", "baggage", "banner", "box", "cloths"};
    searchWord = "bags";
    output = solution.suggestedProducts(products, searchWord);
    for (auto& results : output) {
        print_vector(results);
        cout << ", ";
    }
    cout << '\n';

    cout << "Great success!" << '\n';
}
