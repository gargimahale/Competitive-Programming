#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> cnt(128);
        int req = t.size();
        for (int i=0; i<req; ++i){
            ++cnt[t[i]];
        }
        int min = INT_MAX, start = 0, end = 0, left = 0;
        while(end <= s.size() && start < s.size()){
            if (req){
                if (end == s.size()) break;
                cnt[s[end]]--;
                if (cnt[s[end]] >= 0) req--;
                end++;
            }
            else{
                if (end - start < min){
                    min = end - start;
                    left = start;
                }
                cnt[s[start]]++;
                if (cnt[s[start]] > 0) req++;
                start++;
            }
        }
        return min == INT_MAX ? "": s.substr(left, min);
    }
};