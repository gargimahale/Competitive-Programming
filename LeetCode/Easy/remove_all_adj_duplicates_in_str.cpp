#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        if (!n){
            return "";
        }
        
        string res;
        for (int i = 0; i<n; ++i){
            if (res.back() == s[i]){
                res.pop_back();
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
