#include <bits/stdc++.h>
using namespace std;

/*
Using Floyd Cycle detection Algo
 */

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
        int slow = n, fast = n;
        do {
            slow = helper(slow);
            fast = helper(fast);
            fast = helper(fast);
        } while (slow != fast);
        if (slow == 1) return 1;
        return 0;
    }
};