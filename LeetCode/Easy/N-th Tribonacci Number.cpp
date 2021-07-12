#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n < 3) return 1;

        int f = 0, s = 1, t = 1, k = f + s + t;

        for (int i = 3; i <= n; ++i) {
            k = f + s + t;
            f = s;
            s = t;
            t = k;
        }
        return t;
    }
};