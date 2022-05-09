#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int third = -1000000001;

        for (int i = nums.size() - 1; i >= 0; --i) {
            // third is always the second-biggest element encountered so far
            // so if we encounter a value smaller than this, we can return true
            if (nums[i] < third) {
                return true;
            }
            // If we encounter a value bigger than the top of the stack, pop until we encounter a value smaller or equal
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> input;

    // true
    input = {2, 3, 4, 5, 1, 2, 3};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // true
    input = {3, 5, 4, 3, 4};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // true
    input = {3, 1, 4, 2};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // false (this testcase defeats monotonic increase/decrease approach)
    input = {3, 6, 3};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // false
    input = {1, 2, 3, 4};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;

    // true
    input = {-1, 3, 2, 0};
    cout << (solution.find132pattern(input) ? "true" : "false") << endl;
}
