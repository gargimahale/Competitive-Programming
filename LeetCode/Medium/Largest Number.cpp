#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int& ele: nums){
            arr.push_back(to_string(ele));
        }
        
        sort(begin(arr), end(arr), [&](string a, string b){
            return a+b > b+a;    
        });
        
        string res;
        for (string s: arr) res += s;
        int i = 0;
        
        while (res.size() > 1 && res[i] == '0'){
            res.erase(begin(res));
        }
        
        return res;
    }
};