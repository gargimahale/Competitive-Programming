#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        long long ans = 0;
        for(int x: nums){
            for(int i=1; i<=(1<<22); i*=2){
                if(map.count(i-x)){
                    ans += map[i-x];
                }
            }
            map[x]+=1;
        }
        return ans % (int)(1e9 + 7);
    }
};
