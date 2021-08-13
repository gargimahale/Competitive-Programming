#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int len_g = g.size(), len_s = s.size();

        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int i = 0, j = 0;
        while (i < len_g && j < len_s) {
            if (g[i] <= s[j]) {
                ++i;
            }
            ++j;
        }
        return i;
    }
};