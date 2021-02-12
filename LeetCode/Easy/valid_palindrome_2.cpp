#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isPalindrome(string& s, int start, int end){
        while(start<=end){
            if (s[start]!=s[end]){
                return false;
            }
            start++, end--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0, j=s.size()-1;
        if (s.size() <= 1) return true;
        while(i<=j){
            if (s[i]!=s[j]){
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
            i++, j--;
        }
        return true;
    }
};