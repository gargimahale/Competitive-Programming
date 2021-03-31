#include <bits/stdc++.h>
using namespace std;

class MRUQueue{
public:
    vector<int> Q;

    MRUQueue(int n){
        for (int i = 1; i <= n; ++i)
        {
            Q.push_back(i);
        }
    }

    int fetch(int k){
        int val = Q[k - 1];
        Q.erase(Q.begin() + k - 1);
        Q.push_back(val);
        return val;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
