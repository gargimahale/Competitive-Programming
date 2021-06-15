#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        int idx = 0, i, j;
        for (i = 0, j = 0; i < haystack.size() && j < needle.size();) {
            if (haystack[i] == needle[j]) i++, j++;
            else {
                idx++;
                i = idx;
                j = 0;
            }
        }
        if (j == needle.size()) return idx;
        return -1;
    }
};