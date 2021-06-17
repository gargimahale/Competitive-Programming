#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int getBin(string& s, char ch) {
        int flipCnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ch) {
                ++flipCnt;
            }
            ch = ch == '1' ? '0' : '1';
        }
        return flipCnt;
    }

    int minOperations(string s) {
        return min(getBin(s, '0'), getBin(s, '1'));
    }
};