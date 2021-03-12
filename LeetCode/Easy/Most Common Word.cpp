#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        for(int i=0; i<paragraph.size();){
            string temp = "";
            while(i < paragraph.size() && isalpha(paragraph[i])) {
                paragraph[i] = tolower(paragraph[i]);
                temp += (tolower(paragraph[i]));
                ++i;
            }
            while(i < paragraph.size() && !isalpha(paragraph[i])) ++i;
            mp[temp]++;
        }
        
        for (auto x: banned) mp[x] = 0;
        string res = "";
        int cnt = 0;
        for(auto x: mp){
            if (x.second > cnt){
                res = x.first;
                cnt = x.second;
            }
        }
        return res;
    }
};