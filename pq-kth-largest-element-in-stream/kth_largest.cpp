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
        }
    }

    int add(int val) {
        pq.push(val);

        // Reserve some space for popped elements
        vector<int> temp(k - 1);

        // Pop k-1 elements to reveak k-th element
        for (int i = 0; i < k - 1; ++i) {
            temp[i] = pq.top();
            pq.pop();
        }

        // Store k-th element
        int ret = pq.top();

        // Restore pq
        for (int num : temp) {
            pq.push(num);
        }

        return ret;
    }

   private:
    int k;
    priority_queue<int> pq;
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
