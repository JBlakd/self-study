#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int ret = 0;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            ret = max(ret, area);

            if (height[left] > height[right]) {
                --right;
            } else {
                ++left;
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
    vector<int> height;

    // 49
    height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solution.maxArea(height) << '\n';
}
