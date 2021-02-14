#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int maxPower = 0;
        if (s.empty()) return maxPower;
        
        for (int i=0, j=0; i<s.size() && j < s.size(); ){
            if (i == j || s[i] == s[j]){
                ++j;
                maxPower = max(maxPower, j-i);
            }
            else{
                i = j;
            }
        }
        
        return maxPower;
    }
};