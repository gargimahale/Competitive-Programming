#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int arraySign(vector<int> &nums){
        long ans = 1;
        for (int x : nums){
            ans = (ans * x) % (int)(1e9 + 7);
        }

        if (ans == 0)
            return 0;
        if (ans > 0)
            return 1;
        return -1;
    }
};