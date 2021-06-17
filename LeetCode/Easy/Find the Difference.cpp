#include<bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch;
        for (int i = 0; i < s.size(); ++i) {
            ch ^= (s[i] ^ t[i]);
        }
        return ch ^ t[t.size() - 1];
    }
};