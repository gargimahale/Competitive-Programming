#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeVowels(string s) {
        string res;
        for (char& ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                continue;
            }
            res += ch;
        }
        return res;
    }
};