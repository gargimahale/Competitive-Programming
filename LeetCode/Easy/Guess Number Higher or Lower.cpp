#include <bits/stdc++.h>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int m = lo + (hi - lo) / 2;
            int ans = guess(m);
            if (ans == 0)
                return m;
            else if (ans == -1)
                hi = m - 1;
            else
                lo = m + 1;
        }
        return -1;
    }
};