#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)

class Solution{
public:
    int minDeletions(string s){
        vector<int> cnt(26);
        int res = 0;
        unordered_set<int> used;
        for (char ch : s)
            cnt[ch - 'a']++;

        for (int i = 0; i < 26; ++i){
            int freq = cnt[i];
            while (freq && !used.insert(freq).second){
                --freq;
                ++res;
            }
        }
        return res;
    }
};