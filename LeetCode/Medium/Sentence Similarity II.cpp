#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string find(string& s) {
        if (!mp.count(s)) {
            mp[s] = s;
        }
        while (mp[s] != s) {
            s = mp[s];
        }
        return s;
    }
public:
    unordered_map<string, string> mp;
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int len1 = sentence1.size(), len2 = sentence2.size();
        if (len1 != len2) {
            return false;
        }

        for (auto& it : similarPairs) {
            string p1 = find(it[0]);
            string p2 = find(it[1]);

            if (p1 != p2) {
                mp[p1] = p2;
            }
        }

        for (int i = 0; i < len1; ++i) {
            if (sentence1[i] != sentence2[i] && find(sentence1[i]) != find(sentence2[i])) {
                return false;
            }
        }
        return true;
    }
};