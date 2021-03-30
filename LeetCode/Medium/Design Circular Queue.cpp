#include<bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(capacity)

class MyCircularQueue
{
public:
    vector<int> Q;
    int cap;

    MyCircularQueue(int k){
        cap = k;
    }

    bool enQueue(int value){
        if (Q.size() < cap){
            Q.push_back(value);
            return true;
        }
        return false;
    }

    bool deQueue(){
        if (Q.size() > 0){
            Q.erase(Q.begin());
            return true;
        }
        return false;
    }

    int Front(){
        if (Q.size() > 0){
            return Q[0];
        }
        return -1;
    }

    int Rear()
    {
        if (Q.size() > 0){
            return Q[Q.size() - 1];
        }
        return -1;
    }

    bool isEmpty(){
        return Q.size() == 0;
    }

    bool isFull(){
        return Q.size() == cap;
    }
};