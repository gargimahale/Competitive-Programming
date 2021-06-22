#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool subSeq(string& s, string word) {
        int i = 0, j = 0, m = s.size(), n = word.size();
        while (i < m && j < n) {
            if (s[i] == word[j]) {
                ++i, ++j;
            }
            else {
                ++i;
            }
        }
        return j == n;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int len = words.size();
        int cnt = 0;
        unordered_map<string, int> mp;
        for (string word : words) mp[word]++;

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (subSeq(s, it->first)) {
                cnt += it->second;
            }
        }
        return cnt;
    }
};


// OR

// Time:  O(n + w), n is the size of S, w is the size of words
// Space: O(k), k is the number of words

int numMatchingSubseq(string S, vector<string>& words) {
    vector<pair<int, int>> waiting[128];
    for (int i = 0; i < words.size(); i++)
        waiting[words[i][0]].emplace_back(i, 1);
    for (char c : S) {
        auto advance = waiting[c];
        waiting[c].clear();
        for (auto it : advance)
            waiting[words[it.first][it.second++]].push_back(it);
    }
    return waiting[0].size();
}