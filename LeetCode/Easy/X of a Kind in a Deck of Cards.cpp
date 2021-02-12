#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int res = 0;
        unordered_map<int, int> m;
        for(int x: deck) ++m[x];
        
        // GCD
        for(auto x: m){
            res = __gcd(x.second, res);
        }
        
        return res > 1;
    }
};