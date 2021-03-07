#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long totalSum = 0;
        for (int x: nums) totalSum += x;
        
        totalSum = abs(goal - totalSum);
        return totalSum % limit == 0 ? totalSum/limit : (totalSum+limit)/limit; 
    }
};