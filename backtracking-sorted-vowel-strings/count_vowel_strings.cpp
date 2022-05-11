#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countVowelStrings(int k) {
        // Intuitive one-liner permutation solution
        // {a,e,i,o,u}

        // How many ways to pick n items with replacement from a set of 5?
        // Use the unordered with replacement formula:
        // (n+k-1) Choose k
        // = (n+k-1)! / ( k! (n+k-1-k)! )
        // = (k + 4)! / ( k! (4)!)
        // = (k + 4) * (k + 3) * (k + 2) * (k + 1) / 4!
        return ((k + 4) * (k + 3) * (k + 2) * (k + 1)) / 24;
    }
};

int main() {
    Solution solution;
    int n;

    n = 2;
    cout << solution.countVowelStrings(n) << endl;

    n = 33;
    cout << solution.countVowelStrings(n) << endl;
}
