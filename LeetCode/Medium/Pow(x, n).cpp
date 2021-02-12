#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        double half = myPow(x, n/2);
        double base = n<0 ? 1/x : x;
        return n%2 == 0? half* half : half*half*base;
    }
};