#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)

class Solution{
public:
    void reverseT(string &s, int i, int j){
        while (i < j){
            swap(s[i++], s[j--]);
        }
    }

    void reverseWords(string &s, int n){
        int i = 0, j = 0;
        while (i < n){
            while (i < j || i < n && s[i] == ' ')
                ++i;
            while (j < i || j < n && s[j] != ' ')
                ++j;
            reverseT(s, i, j - 1);
        }
    }

    string cleanedSpaced(string &s, int n){
        int i = 0, j = 0;
        while (j < n){

            // skip spaces
            while (j < n && s[j] == ' ')
                ++j;

            // keep chars
            while (j < n && s[j] != ' ')
                s[i++] = s[j++];

            // skip spaces
            while (j < n && s[j] == ' ')
                ++j;

            // leave only one space
            if (j < n)
                s[i++] = ' ';
        }
        return s.substr(0, i);
    }

    string reverseWords(string s){
        if (s.empty())
            return "";
        int n = s.size();

        // reverse whole string
        reverseT(s, 0, n - 1);

        // reverse each word
        reverseWords(s, n);

        // clean extra spaces
        return cleanedSpaced(s, n);
    }
};