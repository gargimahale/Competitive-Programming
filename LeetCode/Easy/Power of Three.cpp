#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

//  OR
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0)
            return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

// OR
class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};