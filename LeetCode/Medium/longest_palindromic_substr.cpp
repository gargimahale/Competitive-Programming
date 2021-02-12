#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1){
            return s;
        }

        int start=0, max_len = 1, end=0;

        // ODD
        for (int i=0; i<s.size()-1; ++i){
            int l = i, r = i;
            while(l>=0 && r<s.size()){
                if (s[l] == s[r]){
                    l--, r++;
                }
                else{
                    break;
                }
            }

            int len = r-l-1;
            if (len > max_len){
                max_len = len;
                start = l+1;
                end = r-1;
            }
        }

        // EVEN
        for (int i=0; i<s.size()-1; ++i){
            int l = i, r = i+1;
            while(l>=0 && r<s.size()){
                if (s[l] == s[r]){
                    l--, r++;
                }
                else{
                    break;
                }
            }

            int len = r-l-1;
            if (len > max_len){
                max_len = len;
                start = l+1;
                end = r-1;
            }
        }
        return s.substr(start, max_len);
    }
};