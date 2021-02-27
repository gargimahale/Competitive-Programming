#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int countCharacters(vector<string>& words, string chars) {
        string cnt;
        vector<int> cnt1(26);
        for(char ch: chars){
            cnt1[ch-'a']++;
        }
        for (string w: words){
            bool match = true;
            vector<int> check = cnt1;
            for (char ch: w){
                --check[ch-'a'];
                if(check[ch-'a'] < 0){
                    match = false;
                    break;
                }
            }
            if (match){
                cnt += w;
            }   
        }
        return cnt.size();
    }
};