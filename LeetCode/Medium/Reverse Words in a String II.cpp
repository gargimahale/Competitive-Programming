#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void reverseWords(vector<char> &s){
        reverse(s.begin(), s.end());
        int n = s.size(), l = 0, r = 0;
        while (r < n){
            while (r < n && !isspace(s[r]))
                r++;
            reverse(s.begin() + l, s.begin() + r);
            l = ++r;
        }
    }
};