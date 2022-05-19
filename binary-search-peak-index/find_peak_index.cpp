#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Given current index, we always know which side of the peak we're on, based on the gradient
        // binary search until peak is hit
        int lo = 0;
        int hi = arr.size() - 1;
        int mid = 0;
        // loop until either peak is 0 or peak is end or peak is found
        while (true) {
            mid = lo + ((hi - lo) / 2);

            // edge cases
            if (mid == 0) {
                if (arr[1] > arr[0]) {
                    return 1;
                } else {
                    return 0;
                }
            }
            if (mid == arr.size() - 1) {
                if (arr[mid - 1] > arr[mid]) {
                    return mid - 1;
                } else {
                    return mid;
                }
            }

            if (arr[mid + 1] < arr[mid] && arr[mid - 1] < arr[mid]) {
                break;
            }

            if (arr[mid + 1] > arr[mid]) {
                // too left
                lo = mid + 1;
            } else if (arr[mid + 1] < arr[mid]) {
                // too right
                hi = mid - 1;
            }
        }

        return mid;
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
    vector<int> arr;

    arr = {3, 5, 3, 2, 0};
    cout << solution.peakIndexInMountainArray(arr) << endl;

    arr = {0, 1, 0};
    cout << solution.peakIndexInMountainArray(arr) << endl;

    arr = {0, 2, 1, 0};
    cout << solution.peakIndexInMountainArray(arr) << endl;

    arr = {0, 10, 5, 2};
    cout << solution.peakIndexInMountainArray(arr) << endl;
}
