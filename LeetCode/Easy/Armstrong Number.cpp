#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n, int sum = 0) {
        string num = to_string(n);
        for (auto c: num) sum += pow(c-'0', num.size());
        return sum == n;
    }
};