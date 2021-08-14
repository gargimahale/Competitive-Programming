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

// OR

class Solution {
    int findSquare(int& n) {
        long ans = 0;
        while (n > 0) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int& n) {
        unordered_set<int> seen;
        seen.insert(n);
        while (n > 1) {
            n = findSquare(n);
            if (seen.count(n) == 0) {
                seen.insert(n);
            }
            else {
                return false;
            }
        }
        return true;
    }
};