#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long digit = 0;
        while(x){
            digit = digit*10 + x%10;
            x = x / 10;
        }
        return (digit > INT_MAX || digit < INT_MIN) ? 0 : digit;
    }
};