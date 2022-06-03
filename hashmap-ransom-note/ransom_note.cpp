#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        int hashmap[26] = {0};

        for (char c : magazine) {
            ++hashmap[c - 'a'];
        }

        for (char c : ransomNote) {
            if (hashmap[c - 'a'] == 0) {
                return false;
            }

            --hashmap[c - 'a'];
        }

        return true;
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
}
