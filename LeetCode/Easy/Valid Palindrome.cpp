#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
        if (s.empty())
            return true;
        int start = 0, end = s.size() - 1;
        while (start < end){
            while (!isalnum(s[start]) && start < end){
                ++start;
            }
            while (!isalnum(s[end]) && start < end){
                --end;
            }
            if (toupper(s[start++]) != toupper(s[end--]))
                return false;
        }
        return true;
    }
};