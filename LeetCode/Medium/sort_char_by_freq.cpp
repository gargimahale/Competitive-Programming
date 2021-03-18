#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unsigned int cnt[256]={0};
        for (char ch: s) cnt[ch]++;
        sort(s.begin(), s.end(), [&](char a, char b){
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a<b);
        });
        return s;
    }
};

// OR

class Solution {
public:
    string frequencySort(string s) {
        vector<string> vec(127);
        for(auto x: s){
            vec[x] += x;
        }
        
        sort(vec.begin(), vec.end(), [&](string a, string b){
            return a.size() > b.size();
        });
        
        string res = "";
        for(auto x: vec){
            res += x;
        }
        return res;
    }
};