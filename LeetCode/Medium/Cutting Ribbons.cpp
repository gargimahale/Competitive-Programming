#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isValidCut(vector<int>& ribbons, int len, int k){
        int count = 0;
        for (int& x: ribbons){
            count += (x/len);
            if (count >= k){
                return true;
            }
        }
        return false;
    }
public:
    int maxLength(vector<int>& ribbons, int k) {
        int l = 1, r = accumulate(begin(ribbons), end(ribbons), 0l)/k;
        int findVal = 0;
        
        while(l <= r){
            int m = l+(r-l)/2;
            if (isValidCut(ribbons, m, k)){
                findVal = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return findVal;
    }
};