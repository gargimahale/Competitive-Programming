#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> nums, min_check;
    MinStack() {
        nums = stack<int>();
        min_check = stack<int>();
    }

    void push(int x) {
        if (!min_check.empty()) {
            int ele = min_check.top();
            if (x < ele) {
                min_check.push(x);
            }
            else {
                min_check.push(ele);
            }
        }
        else {
            min_check.push(x);
        }
        nums.push(x);
    }

    void pop() {
        if (!nums.empty() && !min_check.empty()) {
            nums.pop();
            min_check.pop();
        }
    }

    int top() {
        return nums.top();
    }

    int getMin() {
        return min_check.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// OR

class MinStack {
public:
    /** initialize your data structure here. */

    vector<int> a, b;
    MinStack() {
        a.clear(), b.clear();
    }

    void push(int x) {
        a.push_back(x);
        if (b.empty()) {
            b.push_back(x);
        }
        else {
            int newMin = min(x, *b.rbegin());
            b.push_back(newMin);
        }
    }

    void pop() {
        a.pop_back();
        b.pop_back();
    }

    int top() {
        return *a.rbegin();
    }

    int getMin() {
        return *b.rbegin();
    }
};

// OR

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stk, my_stk;
    MinStack() {}
    
    void push(int val) {
        if (!my_stk.empty() && my_stk.back() <= val){
            my_stk.push_back(my_stk.back());
        }
        else{
            my_stk.push_back(val);
        }
        stk.push_back(val);
    }
    
    void pop() {
        stk.pop_back();
        my_stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return my_stk.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */