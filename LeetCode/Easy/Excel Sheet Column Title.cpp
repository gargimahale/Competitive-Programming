#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;
        }
        reverse(begin(res), end(res));
        return res;
    }
};