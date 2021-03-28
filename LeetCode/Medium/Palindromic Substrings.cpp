#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void expandPalin(string &s, int left, int right, int &cnt)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            ++cnt, --left, ++right;
        }
    }

    int countSubstrings(string s)
    {
        int cnt = 0;
        if (s.size() == 0)
            return 0;
        for (int i = 0; i < s.size(); ++i)
        {
            expandPalin(s, i, i, cnt);     // odd length
            expandPalin(s, i, i + 1, cnt); // even length
        }
        return cnt;
    }
};