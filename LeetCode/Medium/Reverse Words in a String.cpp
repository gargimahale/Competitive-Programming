#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)

class Solution
{
public:
    void reverseWords(string &s, int n)
    {
        int i = 0, j = 0;
        while (i < n)
        {
            while (i < j || i < n && s[i] == ' ')
                ++i;
            while (j < i || j < n && s[j] != ' ')
                ++j;
            reverse(begin(s) + i, begin(s) + j);
        }
    }

    string cleanedWords(string &s, int n)
    {
        int i = 0, j = 0;
        while (j < n)
        {
            while (j < n && s[j] == ' ')
                ++j;
            while (j < n && s[j] != ' ')
                s[i++] = s[j++];
            while (j < n && s[j] == ' ')
                ++j;
            if (j < n)
                s[i++] = ' ';
        }
        return s.substr(0, i);
    }

    string reverseWords(string s)
    {

        if (s.empty())
            return "";
        int n = s.size();

        // reverse whole string
        reverse(begin(s), end(s));

        // reverse words
        reverseWords(s, n);

        return cleanedWords(s, n);
    }
};