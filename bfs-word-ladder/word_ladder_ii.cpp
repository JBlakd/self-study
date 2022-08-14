#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
      return {};
    }

    unordered_set<string> word_set;
    unordered_set<string> visited;

    vector<vector<string>> ret;

    // Represent wordList as a set, for constant-time searching
    for (string& word : wordList) {
      word_set.insert(word);
    }

    // visited.insert(beginWord);
    queue<vector<string>> todo;
    todo.emplace(vector<string>{beginWord});

    while (!todo.empty()) {
      int n = todo.size();
      vector<string> cur_path;
      for (int queue_count = 0; queue_count < n; ++queue_count) {
        cur_path = todo.front();
        todo.pop();

        // find neighbours
        vector<string> neighbours;
        for (int i = 0; i < cur_path.back().length(); ++i) {
          string potential_neighbour = cur_path.back();
          for (int j = 'a'; j <= 'z'; ++j) {
            potential_neighbour[i] = j;
            // Only include as neighbour if is a valid word, and if not visited
            if (word_set.find(potential_neighbour) != word_set.end()) {
              vector<string> next_path = cur_path;
              next_path.push_back(potential_neighbour);
              visited.insert(potential_neighbour);
              if (potential_neighbour == endWord) {
                ret.push_back(next_path);
              } else {
                todo.emplace(next_path);
              }
            }
          }
        }
      }
      for (auto& word : visited) {
        word_set.erase(word);
      }
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
  string beginWord;
  string endWord;
  vector<string> wordList;
  vector<vector<string>> output;

  beginWord = "red";
  endWord = "tax";
  wordList = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
  output = solution.findLadders(beginWord, endWord, wordList);

  // beginWord = "hit";
  // endWord = "cog";
  // wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  // output = solution.findLadders(beginWord, endWord, wordList);

  cout << "Great success!" << '\n';
}
