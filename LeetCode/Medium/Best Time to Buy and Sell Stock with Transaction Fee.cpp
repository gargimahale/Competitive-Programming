#include<bits/stdc++.h>
using namespace std;

/** 
 * s0 = profit having no stock
 * s1 = profit having 1 stock
 * update s0 by selling the stock from s1, so s0 = max(s0, s1+p);
 * update s1 by buying the stock from s0, so s1 = max(s1, s0-p-fee);
 **/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0, s1 = INT_MIN;
        for(int x: prices){
            int temp = s0;
            s0 = max(s0, s1+x);
            s1 = max(s1, temp-x-fee);
        }
        return s0;
    }
};
