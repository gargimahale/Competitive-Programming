#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (int i = 5; n / i > 0; i *= 5) {
            res += (n / i);
        }
        return res;
    }
};