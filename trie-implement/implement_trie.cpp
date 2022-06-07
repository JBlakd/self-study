#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
   public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
        Node* cur_node = root;

        for (char c : word) {
            if (cur_node->children[c - 'a'] == nullptr) {
                cur_node->children[c - 'a'] = new Node(c);
            }
            cur_node = cur_node->children[c - 'a'];
        }

        cur_node->is_word = true;
    }

    bool search(string word) {
        Node* cur_node = root;

        for (char c : word) {
            if (cur_node->children[c - 'a'] == nullptr) {
                return false;
            }
            cur_node = cur_node->children[c - 'a'];
        }

        return cur_node->is_word;
    }

    bool startsWith(string prefix) {
        Node* cur_node = root;

        for (char c : prefix) {
            if (cur_node->children[c - 'a'] == nullptr) {
                return false;
            }
            cur_node = cur_node->children[c - 'a'];
        }

        return true;
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

    Node* root;
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
    Trie trie;
    trie.insert("apple");
    // 1
    cout << trie.search("apple") << '\n';
    // 0
    cout << trie.search("app") << '\n';
    // 1
    cout << trie.startsWith("app") << '\n';
    trie.insert("app");
    // 1
    cout << trie.search("app") << '\n';
}
