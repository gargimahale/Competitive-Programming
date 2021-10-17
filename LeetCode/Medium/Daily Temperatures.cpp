#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> S;
        vector<int> res(n, 0);
        
        for (int i = 0; i < n; ++i){
            while(!S.empty() && T[S.top()] < T[i]){
                int j = S.top();
                S.pop();
                res[j] = i-j;
            }
            S.push(i);
        }
        return res;
    }
};