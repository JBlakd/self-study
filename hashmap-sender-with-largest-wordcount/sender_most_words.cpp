#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> sender_word_map;
        for (auto& sender : senders) {
            sender_word_map[sender] = 0;
        }

        // count the number of spaces in messages. cur_msg_word_count == spaces + 1
        for (int i = 0; i < messages.size(); ++i) {
            int cur_msg_word_count = 1;
            for (char c : messages[i]) {
                if (c == ' ') {
                    ++cur_msg_word_count;
                }
            }
            sender_word_map[senders[i]] += cur_msg_word_count;
        }

        // Iterate through senders, find out the most-sent messages value
        int max_count = 0;
        for (auto& [sender, word_count] : sender_word_map) {
            max_count = max(max_count, word_count);
        }

        priority_queue<string> most_sent_senders;
        for (auto& [sender, word_count] : sender_word_map) {
            if (word_count == max_count) {
                most_sent_senders.push(sender);
            }
        }

        return most_sent_senders.top();
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
    vector<string> messages;
    vector<string> senders;

    // Alice
    messages = {"Hello userTwooo", "Hi userThree", "Wonderful day Alice", "Nice day userThree"};
    senders = {"Alice", "userTwo", "userThree", "Alice"};
    cout << solution.largestWordCount(messages, senders) << endl;

    // Charlie
    messages = {"How is leetcode for everyone", "Leetcode is useful for practice"};
    senders = {"Bob", "Charlie"};
    cout << solution.largestWordCount(messages, senders) << endl;
}
