#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0;
        string temp = s;
        reverse(begin(temp), end(temp));
        if (s == temp) return 1;
        return 2;
    }
};