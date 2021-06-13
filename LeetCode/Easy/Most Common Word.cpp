#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;

        int n = para.size();
        if (n == 0) return para;

        for (auto& ch : para) c = isalpha(ch) ? tolower(ch) : ' ';

        istringstream iss(para);
        string w;
        pair<string, int> res("", 0);
        while (iss >> w) {
            if (ban.find(w) == ban.end() && ++count[w] > res.second) {
                res = make_pair(w, count[w]);
            }
        }
        return res.first;
    }
};

// TC: (N+M)
// SC: O(N+M)
// where n - is for the pipeline
// m - is for the set