#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp (s.size(), false);
        dp[0] = true;

        for(int i = 0; i < s.size(); ++i){
            if (dp[i]){
                for (string word: wordDict){
                    int j = i+word.size()-1;
                    if (j<s.size() && word == s.substr(i, word.size())){
                        if (j == s.size()-1){
                            return true;
                        }
                        else{
                            dp[j+1] = true;
                        }
                    }
                }
            }
        }
        return false;
    }
};