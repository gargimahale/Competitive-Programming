#include <bits/stdc++.h>
using namespace std;


// Time: O(N), Space: O(128) -> O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> cnt(128);
        int num = 0, i = 0, res = 0;
        
        for (int j = 0; j<s.size(); ++j){
            if (cnt[s[j]]++ == 0) ++num;
            
            if (num > k){
                while(--cnt[s[i++]] > 0);
                --num;
            }
            res = max(res, j-i+1);
        }
        
        return res;
    }
};
