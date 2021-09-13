#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool validIP(string& s, int start, int end){
        string temp = s.substr(start, end-start+1);
        int ip = stoll(temp);
        
        if (s[start] == '0' && start != end){
            return false;
        }
        
        if (ip >= 0 && ip <= 255)
            return true;
        
        return false;
    }
    
    void helper(string& s, int start, int part){
        if (start == s.size() && part == 4){
            res.push_back(inp);
            return;
        }
        
        for (int i = start; i<s.size(); ++i){
            if (part < 4 && i-start < 3 && validIP(s, start, i)){
                inp.append(s.substr(start, i-start+1));
                ++part;
                
                if (part < 4){
                    inp.push_back('.');
                }
                
                helper(s, i+1, part);
                
                if (part < 4){
                    inp.pop_back();
                }
                --part;
                
                for (int j = 0; j<i-start+1; ++j){
                    inp.pop_back();
                }
            }
        }
    }
public:
    vector<string> res;
    string inp;
    
    vector<string> restoreIpAddresses(string s) {
        helper(s, 0, 0);
        return res;
    }
};