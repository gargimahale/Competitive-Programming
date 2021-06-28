#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int len = s.size();
        vector<pair<int, string>> temp(len);
        string res = "";
        for (int i = 0; i < indices.size(); ++i) {
            if (s.compare(indices[i], sources[i].size(), sources[i]) == 0) {
                temp[indices[i]] = {sources[i].size(), targets[i]};
            }
        }

        for (int i = 0; i < len; ++i) {
            if (temp[i].first == 0) {
                res += s[i];
            }
            else {
                res += temp[i].second;
                i += temp[i].first - 1;
            }
        }
        return res;
    }
};