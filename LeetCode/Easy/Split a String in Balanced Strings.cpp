#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        for (int i = 0, bal = 0; i < s.size(); ++i) {
            if (s[i] == 'R') ++bal;
            if (s[i] == 'L') --bal;
            if (bal == 0) {
                res += 1;
            }
        }
        return res;
    }
};