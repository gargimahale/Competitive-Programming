#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<string>mp;
        for(int i = 0; i <= s.size()-k; ++i){
           mp.insert(s.substr(i, k));
        }
        return mp.size() == pow(2, k);
    }
};