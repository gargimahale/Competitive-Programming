#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int p1 = -1, p2 = -1, minDist = INT_MAX;
        int len = wordsDict.size();
        for (int i = 0; i < len; ++i) {
            if (word1.compare(wordsDict[i]) == 0) {
                p1 = i;
            }
            if (word2.compare(wordsDict[i]) == 0) {
                p2 = i;
            }

            if (p1 >= 0 && p2 >= 0)
                minDist = min(minDist, abs(p1 - p2));
        }
        return minDist;
    }
};