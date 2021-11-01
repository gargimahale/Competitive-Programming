#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int operations[1001] = {}, cnt = 0;
        vector<int> q{goal};
        
        while(!q.empty()){
            ++cnt;
            vector<int> q1;
            for (int& x: q){
                for (int n: nums){
                    for (int xn: {x + n, x - n, x ^ n}){
                        if (xn >= 0 && xn <= 1000 && operations[xn] == 0){
                            operations[xn] = cnt;
                            q1.push_back(xn);
                        }
                    }
                }
            }
            swap(q, q1);
        }
        return operations[start] == 0 ? -1: operations[start];
    }
};
