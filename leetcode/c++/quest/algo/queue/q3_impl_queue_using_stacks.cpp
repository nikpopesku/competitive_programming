#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        back = {};
        front = {};
    }

    void push(const int x) {
        back.push(x);
    }

    int pop() {
        const int elem = front.top();
        front.pop();

        return elem;
    }

    int peek() {
        return front.top();
    }

    bool empty() {
        return front.empty() && back.empty();
    }
private:
    stack<int> front;
    stack<int> back;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    auto s = Solution();
    vector<int> tickets = {2, 3, 2};
    cout << s.timeRequiredToBuy(tickets, 2) << '\n'; //6

    vector<int> tickets2 = {5, 1, 1, 1};
    cout << s.timeRequiredToBuy(tickets2, 0) << '\n'; //8
}
