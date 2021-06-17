#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(begin(words), end(words));
        unordered_set<string> built;
        string res;
        for (string s : words) {
            if (s.size() == 1 || built.count(s.substr(0, s.size() - 1))) {
                res = s.size() > res.size() ? s : res;
                built.insert(s);
            }
        }
        return res;
    }
};