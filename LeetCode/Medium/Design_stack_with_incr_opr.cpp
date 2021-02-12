#include <bits/stdc++.h>

using namespace std;

class CustomStack {
public:
    
    int cap;
    vector<int> stack;
    CustomStack(int maxSize) {
        cap = maxSize;
    }
    
    void push(int x) {
        if (stack.size() != cap){
            stack.push_back(x);
        }
        return;
    }
    
    int pop() {
        if (stack.size() > 0){
            int ele = stack[stack.size()-1];
            stack.pop_back();
            return ele;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if (stack.size() == 0){
            return;
        }
        int n = stack.size();
        int check = min(k, n);
        for(int i=0; i<check; ++i){
            stack[i] += val;
        }
    }
};


// OR

class CustomStack {
public:
    vector<int> stack;
    int size;
    
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < size){
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (!stack.empty()){
            int top = *stack.rbegin();
            stack.pop_back();
            return top;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if (stack.size() == 0){
            return;
        }
        int i=0;
        while(k-- > 0 && i < stack.size()){
            stack[i++] += val;
        }
    }
};