#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n <= 1){
            return true;
        }
        int start = 0, end = n-1;
        while(start < end){
            while(start < end && !isalnum(s[start])){
                ++start;
            }
            while(start < end && !isalnum(s[end])){
                --end;
            }
            if (tolower(s[start]) != tolower(s[end])){
                return false;
            }
            ++start, --end;
        }
        return true;
    }
};