#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.size();
        while(j < n){
            while(i < j || (j < n && s[i] == ' ')) ++i;
            while(j < i || (j < n && s[j] != ' ')) ++j;
            reverse(begin(s)+i, begin(s)+j);
        }
        return s;
    }
};

// TC: O(N), SC: O(1)