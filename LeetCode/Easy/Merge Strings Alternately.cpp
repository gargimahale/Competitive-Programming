#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int i = 0, j = 0;
        int x = 0;
        string ans;

        while (i < n || j < m) {
            if ((x == 1 && j < m) || (i == n)) {
                ans += word2[j++];
            }
            else {
                ans += word1[i++];
            }
            x ^= 1;
        }
        return ans;
    }
};


// OR
string mergeAlternately(string w1, string w2) {
    int i = 0, j = 0;
    string res;
    while (i < w1.size() && j < w2.size())
        res += string() + w1[i++] + w2[j++];
    return res + w1.substr(i) + w2.substr(j);
}