#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26, 0);
        for (int i = 0; i<order.size(); ++i){
            cnt[order[i]-'a'] = i+1;
        }
        
        sort(begin(s), end(s), [&](char a, char b){
            return cnt[a-'a'] < cnt[b-'a']; 
        });
        return s;
    }
};