#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m;
        --n;
        int i = nums1.size() - 1;

        while (i >= 0) {
            if (n < 0 || (m >= 0 && nums1[m] >= nums2[n])) {
                // choose from nums1
                nums1[i] = nums1[m];
                --m;
            } else {
                // choose from nums2
                nums1[i] = nums2[n];
                --n;
            }

            --i;
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
    vector<int> nums1;
    int m;
    vector<int> nums2;
    int n;

    nums1 = {1, 2, 3, 0, 0, 0};
    m = 3;
    nums2 = {2, 5, 6};
    n = 3;
    solution.merge(nums1, m, nums2, n);
    print_vector(nums1);
    cout << '\n';

    nums1 = {2, 5, 6, 0, 0, 0};
    m = 3;
    nums2 = {1, 2, 3};
    n = 3;
    solution.merge(nums1, m, nums2, n);
    print_vector(nums1);
    cout << '\n';

    nums1 = {0};
    m = 0;
    nums2 = {1};
    n = 1;
    solution.merge(nums1, m, nums2, n);
    print_vector(nums1);
    cout << '\n';
}
