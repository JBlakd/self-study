#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            // At all times we only keep the k biggest elements
            // Since this is a MIN pq, the k-th biggest element always remains at the top
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        // At all times we only keep the k biggest elements
        if (pq.size() > k) {
            pq.pop();
        }
        // Since this is a MIN pq, the k-th biggest element always remains at the top
        return pq.top();
    }

   private:
    int k;
    // MIN pq
    priority_queue<int, vector<int>, greater<int>> pq;
};

int main() {
    KthLargest* solution;
    int k;
    vector<int> nums;
    vector<int> vals;

    k = 3;
    nums = {4, 5, 8, 2};
    vals = {3, 5, 10, 9, 4};
    solution = new KthLargest(k, nums);
    for (int val : vals) {
        cout << solution->add(val) << ", ";
    }
    cout << endl;
    delete solution;
}
