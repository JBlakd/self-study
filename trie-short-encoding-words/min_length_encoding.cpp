#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        // New concept unlocked: backwards trie
        root = new Node();

        for (string& word : words) {
            Node* cur_node = root;
            for (int i = word.length() - 1; i >= 0; --i) {
                if (cur_node->children[word[i] - 'a'] == nullptr) {
                    cur_node->children[word[i] - 'a'] = new Node(word[i]);
                }
                cur_node = cur_node->children[word[i] - 'a'];
            }
            cur_node->is_word = true;
        }

        // dfs for leaf nodes which are also words
        int ret = 0;
        int cur_depth = 0;
        dfs(root, cur_depth, ret);

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

    void dfs(Node* cur_node, int& cur_depth, int& ret) {
        bool has_child = false;

        // visit children
        for (Node*& child : cur_node->children) {
            if (child != nullptr) {
                has_child = true;
                ++cur_depth;
                dfs(child, cur_depth, ret);
                --cur_depth;
            }
        }

        if (!has_child && cur_node->is_word) {
            ret += cur_depth + 1;
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
    int output;

    // climb#
    words = {"climb", "limb", "climb", "climb"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 6);

    // time#
    words = {"time", "time", "time", "time"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // climb#
    words = {"climb", "limb"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 6);

    // time#
    words = {"time"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // qwosp#grahp# 12
    words = {"p", "grahp", "qwosp"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 12);

    // chime#bell# 11
    words = {"chime", "ime", "me", "bell"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 11);

    // time# 5
    words = {"me", "time", "ime"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // time# 5
    words = {"time", "me"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // time# 5
    words = {"me", "time"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 5);

    // chime#time#bell# 16
    words = {"chime", "time", "me", "bell"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 16);

    // t# 2
    words = {"t"};
    output = solution.minimumLengthEncoding(words);
    cout << output << '\n';
    assert(output == 2);

    cout << "Great success!" << '\n';
}
