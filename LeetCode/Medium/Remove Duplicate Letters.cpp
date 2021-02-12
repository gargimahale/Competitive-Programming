#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        bool taken[26] = {false};
        for (char ch: s){
            count[ch-'a']++;
        }
        
        string result = "";
        for (char ch: s){
            int it = ch-'a';
            count[it]--;
            
            if (taken[it]){
                continue;
            }
            
            while(!result.empty() && ch < result.back() && count[result.back()-'a']){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }
            
            result += ch;
            taken[it] = true;
        }
        return result;
    }
};