#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if (!n){
            return "/";
        }
        string res, inp;
        istringstream iss(path);
        vector<string> temp;
        
        while(getline(iss, inp, '/')){
            if (inp == "" || inp == "."){
                continue;
            }
            if (inp == ".." && !temp.empty()){
                temp.pop_back();
            }
            if (inp != ".."){
                temp.push_back(inp);
            }
        }
        
        for (string& x: temp){
            res += "/" + x;
        }
        
        return res.empty() ? "/": res;
    }
};