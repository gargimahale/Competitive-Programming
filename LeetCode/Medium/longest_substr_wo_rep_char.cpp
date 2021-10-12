#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n < 2){
            return n;
        }
        
        vector<int> count(128, 0);
        count[s[0]]++;
        
        int i = 0, j = 0, maxLen = 1;
        while(j < n-1){
            if (count[s[j+1]] == 0){
                count[s[++j]]++;
                maxLen = max(maxLen, j-i+1);
            }
            else{
                count[s[i++]]--;
            }
        }
        return maxLen;
    }
};

