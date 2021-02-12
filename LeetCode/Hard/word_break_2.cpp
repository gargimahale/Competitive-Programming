#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, vector<string>> dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (dp.find(s) != dp.end()) return dp[s];
        vector<string> result;
        for (string word: wordDict){
            if(s.substr(0, word.length()) == word){
                if(word.length() == s.length()){
                    result.push_back(word);
                }
                else{
                    vector<string> temp = wordBreak(s.substr(word.length()), wordDict);
                    for(string tmp: temp){
                        result.push_back(word + " " + tmp);
                    }
                }
            }
        }
        dp[s] = result;
        return result;
    }
};