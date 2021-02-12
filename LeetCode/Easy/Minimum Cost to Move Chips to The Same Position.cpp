#include <bits/stdc++.h>

using namespace std;

/*
// We can consolidate all odd and all even chips together at no cost. 
So, we will have two piles in the end, and we move chips from the smaller pile to the 
larger one.
Solution: Count chips in even and odd positions. Return the smaller count.
*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cnt[2] = {0};
        for (auto& p: position){
            ++cnt[p%2];
        }
        
        return min(cnt[1], cnt[0]);
    }
};