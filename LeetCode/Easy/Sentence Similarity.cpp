#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int len1 = sentence1.size(), len2 = sentence2.size();
        if (len1 != len2) return false;

        unordered_map<string, set<string>> mp;
        for (auto& it : similarPairs) {
            mp[it[0]].emplace(it[1]);
        }

        for (int i = 0; i < len1; ++i) {
            if (sentence1[i] != sentence2[i] && !mp[sentence1[i]].count(sentence2[i]) && !mp[sentence2[i]].count(sentence1[i])) {
                return false;
            }
        }
        return true;
    }
};