#include <bits/stdc++.h>
using namespace std;


// Time: O(N), Space: O(1)
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (n == 0 || k > n){
            return 0;
        }
        
        vector<int> count(26);
        for (int i = 0; i < n; ++i){
            count[s[i]-'a']++;
        }
        
        for (int i = 0; i < n; ++i){
            if (count[s[i]-'a'] >= k){
                continue;
            }
            int j = i+1;
            while(j < n && count[s[j]-'a'] < k) ++j;
            return max({longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(j), k)});
        }
        return s.size();
    }
};