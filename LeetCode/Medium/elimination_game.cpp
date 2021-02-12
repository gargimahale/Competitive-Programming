#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int start = 1, direction = 0, diff = 1;
        while(n > 1){
            if (direction == 0 || n & 1){
                start += diff;
            }
            n/=2;
            diff *= 2;
            direction = !direction;
        }
        return start;
    }
};