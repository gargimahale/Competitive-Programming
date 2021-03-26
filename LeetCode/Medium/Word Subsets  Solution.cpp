#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countOccurances(string &s){
        vector<int> cnt(26);
        for (char ch : s){
            cnt[ch - 'a']++;
        }
        return cnt;
    }

    vector<string> wordSubsets(vector<string> &A, vector<string> &B){
        vector<int> tmp(26), cnt(26);
        vector<string> res;
        for (string word : B){
            tmp = countOccurances(word);
            for (int i = 0; i < 26; ++i){
                cnt[i] = max(cnt[i], tmp[i]);
            }
        }

        int i;
        for (string word : A){
            tmp = countOccurances(word);
            for (i = 0; i < 26; ++i){
                if (tmp[i] < cnt[i])
                    break;
            }
            if (i == 26)
                res.push_back(word);
        }
        return res;
    }
};
