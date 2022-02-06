#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

   void fill_lps(string &s, int lps[]){
       int len =0;
       lps[0] = 0;
       int n = s.length();
       int i =1;
       while(i < n){
           if(s[len] == s[i]){
               len++;
               lps[i] = len;
               i++;
           }
           else if(len != 0){
               len = lps[len-1];
           }
           else{
               lps[i] = 0;
               i++;
           }
       }
       return;
   }

    string shortestPalindrome(string s) {
        int n = s.length();
        if(n == 0 || n == 1) return s;

        int lps[n];
        fill_lps(s, lps);
        int len = 0, i = n-1;
        while (i >= 0){
            if(s[i] == s[len]){
                len++;
                i--;
            }
            else if(len != 0){
                len = lps[len-1];
            }
            else{
                i--;
            }
        }
        string ans;
        cout<<len;
        for(int i = n-1; i>= len; i--)
            ans.push_back(s[i]);
        ans += s;
        return ans;

    }
};