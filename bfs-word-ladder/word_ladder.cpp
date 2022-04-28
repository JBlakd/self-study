#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set;
        unordered_set<string> visited;

        int ladder_length = 0;

        // Represent wordList as a set, for constant-time searching
        for (string word : wordList) {
            word_set.insert(word);
        }

        queue<string> todo;
        visited.insert(beginWord);
        todo.push(beginWord);

        bool found = false;

        while (!todo.empty()) {
            int n = todo.size();
            string cur_word;
            for (int queue_count = 0; queue_count < n; ++queue_count) {
                cur_word = todo.front();
                todo.pop();

                if (cur_word.compare(endWord) == 0) {
                    found = true;
                    break;
                }

                // find neighbours
                vector<string> neighbours;
                for (int i = 0; i < cur_word.length(); ++i) {
                    for (int j = 'a'; j <= 'z'; ++j) {
                        string potential_neighbour = cur_word;
                        potential_neighbour[i] = j;
                        // Only include as neighbour if is a valid word, and if not visited
                        if (word_set.find(potential_neighbour) != word_set.end() && visited.find(potential_neighbour) == visited.end()) {
                            neighbours.push_back(potential_neighbour);
                        }
                    }
                }

                // for all neighbours
                for (string neighbour : neighbours) {
                    if (visited.find(neighbour) == visited.end()) {
                        visited.insert(neighbour);
                        todo.push(neighbour);
                    }
                }
            }

            // Increment ladder length
            ++ladder_length;
            if (found) {
                break;
            }
        }

        if (found) {
            return ladder_length;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<string> wordlist;
    string begin_word;
    string end_word;

    wordlist = {"hot", "cog", "dog", "tot", "hog", "hop", "pot", "dot"};
    begin_word = "hot";
    end_word = "dog";
    cout << solution.ladderLength(begin_word, end_word, wordlist) << endl;

    wordlist = {"hot", "dot", "dog", "lot", "log", "cog"};
    begin_word = "hit";
    end_word = "cog";
    cout << solution.ladderLength(begin_word, end_word, wordlist) << endl;

    wordlist = {"hot", "dot", "dog", "lot", "log"};
    begin_word = "hit";
    end_word = "cog";
    cout << solution.ladderLength(begin_word, end_word, wordlist) << endl;
}
