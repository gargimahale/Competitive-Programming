#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int addDigits(int num) {
        if (num <= 9) return num;
        while (true) {
            num = helper(num);
            if (num <= 9) return num;
        }
        return num;
    }
};