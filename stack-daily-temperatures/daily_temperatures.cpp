#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size());
        // <temperature, index>
        stack<pair<int, int>> temperature_stack;

        for (int i = 0; i < temperatures.size(); ++i) {
            if (temperature_stack.empty() || temperatures[i] <= temperature_stack.top().first) {
                temperature_stack.emplace(temperatures[i], i);
            } else {
                while (!temperature_stack.empty() && temperature_stack.top().first < temperatures[i]) {
                    ret[temperature_stack.top().second] = i - temperature_stack.top().second;
                    temperature_stack.pop();
                }
                temperature_stack.emplace(temperatures[i], i);
            }
        }

        // post-process end-temperatures with no warmer days
        while (!temperature_stack.empty()) {
            ret[temperature_stack.top().second] = 0;
            temperature_stack.pop();
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
    vector<int> temperatures;
    vector<int> output;

    temperatures = {69};
    output = solution.dailyTemperatures(temperatures);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{0}));

    temperatures = {9, 8, 7, 6, 5, 4, 3};
    output = solution.dailyTemperatures(temperatures);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{0, 0, 0, 0, 0, 0, 0}));

    temperatures = {30, 60, 90};
    output = solution.dailyTemperatures(temperatures);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{1, 1, 0}));

    temperatures = {30, 40, 50, 60};
    output = solution.dailyTemperatures(temperatures);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{1, 1, 1, 0}));

    temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    output = solution.dailyTemperatures(temperatures);
    print_vector(output);
    cout << '\n';
    assert((output == vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));

    cout << "Great success!" << '\n';
}
