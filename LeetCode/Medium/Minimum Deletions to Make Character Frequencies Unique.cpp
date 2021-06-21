#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)

class Solution {
public:
    int minDeletions(string s) {
        int cnt[26] = {0};
        for (char ch : s) cnt[ch - 'a']++;
        unordered_set<int> used;
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            for (; cnt[i] > 0 && !used.insert(cnt[i]).second; --cnt[i]) {
                ++res;
            }
        }
        return res;
    }
};