#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MyStack {
   public:
    MyStack() {
    }

    void push(int x) {
        if (queue.empty()) {
            queue.push(x);
            return;
        }
        // pop and push n-1 times, queue should now be stack-ordered
        queue.push(x);
        for (int i = 1; i <= queue.size() - 1; ++i) {
            int temp = queue.front();
            queue.pop();
            queue.push(temp);
        }
    }

    int pop() {
        int temp = queue.front();
        queue.pop();
        return temp;
    }

    int top() {
        return queue.front();
    }

    bool empty() {
        return queue.empty();
    }

   private:
    queue<int> queue;
};

int main() {
    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    cout << myStack->pop() << endl;                         // return 2
    cout << myStack->pop() << endl;                         // return 2
    cout << myStack->pop() << endl;                         // return 1
    cout << (myStack->empty() ? "true" : "false") << endl;  // return true
    delete myStack;
}
