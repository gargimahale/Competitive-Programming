#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for(char ch: tasks){
            ++mp[ch];
            maxFreq = max(maxFreq, mp[ch]);
        }
        
        int cycles = (maxFreq-1) * (n+1);
        for (auto x: mp) if (x.second == maxFreq) ++cycles;
        return max((int)tasks.size(), cycles);
    }
};