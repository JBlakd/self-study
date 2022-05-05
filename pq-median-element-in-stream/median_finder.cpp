#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
   public:
    MedianFinder() : k(0) {
    }

    void addNum(int num) {
        ++k;
        if (k % 2 == 0) {
            max_pq.emplace(num);
            min_pq.emplace(max_pq.top());
            max_pq.pop();
        } else {
            min_pq.emplace(num);
            max_pq.emplace(min_pq.top());
            min_pq.pop();
        }
    }

    double findMedian() {
        if (k % 2 == 0) {
            return (min_pq.top() + max_pq.top()) / 2.0;
        } else {
            return max_pq.top();
        }
    }

   private:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    int k;
};
int main() {
    MedianFinder* solution;

    solution = new MedianFinder();
    solution->addNum(1);
    cout << solution->findMedian() << ", ";
    solution->addNum(2);
    cout << solution->findMedian() << ", ";
    solution->addNum(3);
    cout << solution->findMedian() << ", ";
    solution->addNum(4);
    cout << solution->findMedian() << ", ";
    solution->addNum(5);
    cout << solution->findMedian() << ", ";
    solution->addNum(6);
    cout << solution->findMedian() << ", ";
    solution->addNum(7);
    cout << solution->findMedian() << ", ";
    solution->addNum(8);
    cout << solution->findMedian() << ", ";
    solution->addNum(9);
    cout << solution->findMedian() << ", ";
    solution->addNum(10);
    cout << solution->findMedian() << ", ";
    cout << endl;
    delete solution;

    solution = new MedianFinder();
    solution->addNum(3);
    cout << solution->findMedian() << ", ";
    solution->addNum(9);
    cout << solution->findMedian() << ", ";
    solution->addNum(7);
    cout << solution->findMedian() << ", ";
    solution->addNum(6);
    cout << solution->findMedian() << ", ";
    solution->addNum(17);
    cout << solution->findMedian() << ", ";
    solution->addNum(1);
    cout << solution->findMedian() << ", ";
    cout << endl;
    delete solution;
}
