#include <bits/stdc++.h>

using namespace std;

// Can also be implemented using two stacks like min stack question
class MaxStack {
public:
    /** initialize your data structure here. */
    list<int> dll;
    map<int, vector<list<int>::iterator>>m;

    MaxStack() {
        dll.clear();
        m.clear();
    }

    void push(int x) {
        dll.push_front(x);
        m[x].push_back(dll.begin());
    }

    int pop() {
        int x = dll.front();
        m[x].pop_back();
        if (m[x].empty()) {
            m.erase(x);
        }
        dll.pop_front();
        return x;
    }

    int top() {
        return dll.front();
    }

    int peekMax() {
        return m.rbegin()->first;
    }

    int popMax() {
        int x = m.rbegin()->first;
        auto it = m[x].back();
        m[x].pop_back();
        if (m[x].empty()) {
            m.erase(x);
        }
        dll.erase(it);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */


// OR
class MaxStack {
public:
    /** initialize your data structure here. */
    stack<int> stk, mStk;
    MaxStack() {}

    void addMax(int x) {
        if (mStk.empty() || x >= mStk.top()) {
            mStk.push(x);
        }
    }

    void push(int x) {
        addMax(x);
        stk.push(x);
    }

    int pop() {
        int val = stk.top();
        if (val == mStk.top()) {
            mStk.pop();
        }
        stk.pop();
        return val;
    }

    int top() {
        return stk.top();
    }

    int peekMax() {
        return mStk.top();
    }

    int popMax() {
        int val = mStk.top();
        stack<int> tmp;

        while (mStk.top() != stk.top()) {
            tmp.push(stk.top());
            stk.pop();
        }

        mStk.pop();
        stk.pop();

        while (!tmp.empty()) {
            stk.push(tmp.top());
            addMax(tmp.top());
            tmp.pop();
        }

        return val;
    }
};



class MaxStack {
public:
    /** initialize your data structure here. */
    vector<int> stk, my_stk;
    MaxStack() {
        stk.clear();
        my_stk.clear();
    }
    
    void addMax(int& x){
        if (my_stk.empty() || my_stk.back() <= x){
            my_stk.push_back(x);
        }
    }
    
    void push(int x) {
        stk.push_back(x);
        addMax(x);
    }
    
    int pop() {
        int ele = stk.back();
        stk.pop_back();
        
        if (my_stk.back() == ele){
            my_stk.pop_back();
        }
        return ele;
    }
    
    int top() {
        return stk.back();
    }
    
    int peekMax() {
        return my_stk.back();
    }
    
    int popMax() {
        vector<int> temp;
        int ele = my_stk.back();
        while(!stk.empty() && ele != stk.back()){
            temp.push_back(stk.back());
            stk.pop_back();
        }
        
        stk.pop_back();
        my_stk.pop_back();
        
        while(!temp.empty()){
            stk.push_back(temp.back());
            addMax(temp.back());
            temp.pop_back();
        }
        return ele;
    }
};
