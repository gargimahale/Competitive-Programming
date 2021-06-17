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