#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int a = s.size(), b = t.size();
        if ((a == 0 && b == 0) || abs(a - b) > 1) return false;
        if (b < a) swap(s, t);

        int i = 0, j = 0;
        bool foundDiff = false;

        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {

                if (foundDiff) return false;
                foundDiff = true;

                if (s.size() == t.size()) {
                    // replace
                    ++i;
                }
            }
            else {
                ++i;
            }
            ++j;
        }
        return (foundDiff == false && a == b) ? false : true;
    }
};