#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        int curr = -1, n = s.size(), i = 0;
        while(i < n){
            while(i < n && !isdigit(s[i])) ++i;
            if (i >= n) break;
            
            int num = 0;
            while (i < n && isdigit(s[i])){
                num = num * 10 + (s[i++]-'0');
            }
            
            if (num > curr){
                curr = num;
            }
            else{
                return false;
            }
        }
        return true;
    }
};