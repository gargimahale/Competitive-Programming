#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, n = gas.size();
        for (int i = 0; i < n; ++i){
            total += (gas[i]-cost[i]);
        }
        
        if (total < 0){
            return -1;
        }
        
        int tank = 0, start = 0;
        for (int i = 0; i < n; ++i){
            tank += (gas[i]-cost[i]);
            if (tank < 0){
                start = i+1;
                tank = 0;
            }
        }
        return start;
    }
};