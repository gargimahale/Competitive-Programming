#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int helper(int n) {
        int sum = 0;
        while (n) {
            sum += ((n % 10) * (n % 10));
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> S;
        while (true) {
            if (n == 1) return true;
            n = helper(n);
            if (S.count(n) > 0) return false;
            S.insert(n);
        }
        return false;
    }
};