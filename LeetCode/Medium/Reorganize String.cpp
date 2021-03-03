#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> cnt(26);

        // Keeping a track of the most frequent character
        int mostFreq = 0, i = 0;
        for(char ch: S){
            if (++cnt[ch-'a'] > cnt[mostFreq]) {
                mostFreq = ch-'a';
            }
        }
        
        // Bound check if character is repeated
        if (2 * cnt[mostFreq] - 1 > S.size()) return "";
        
        // Adds the most frequent character to alternate position
        while(cnt[mostFreq]){
            S[i] = ('a'+mostFreq);
            i += 2;
            cnt[mostFreq]--;
        }
        
        // Adds the rest of the characters alternately till their count is greater than 0        
        for (int j=0; j<26; ++j){
            while(cnt[j]){
                if (i >= S.size()) i = 1;
                S[i] = ('a'+j);
                cnt[j]--;
                i += 2;
            }
        }
        return S;
    }
};



// TC: O(n)
// SC: O(n) if we consider the output array else it's O(1)
