#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> Q, temp;
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(Q.empty()){
            Q.push(x);
        }
        else{
            while(!Q.empty()){
                temp.push(Q.top());
                Q.pop();
            }
            
            Q.push(x);
            
            while(!temp.empty()){
                Q.push(temp.top());
                temp.pop();
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = Q.top();
        Q.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return Q.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */