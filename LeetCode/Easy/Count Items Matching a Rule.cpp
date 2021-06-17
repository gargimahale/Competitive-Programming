#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> type, color, name;
        for (auto x : items) {
            type[x[0]]++;
            color[x[1]]++;
            name[x[2]]++;
        }

        if (ruleKey == "type") {
            return type[ruleValue];
        }
        else if (ruleKey == "color") {
            return color[ruleValue];
        }
        return name[ruleValue];
    }
};