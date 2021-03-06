#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> Q;

    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        Q.push(x);
        for (int i = 0; i < Q.size() - 1; ++i) {
            Q.push(Q.front());
            Q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = Q.front();
        Q.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return Q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */