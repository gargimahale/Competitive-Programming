#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size();
        int l = m[0][0], r = m[n-1][n-1];
        while(l <= r){
            int mid = l+(r-l)/2;
            int num = 0;
            for (int i=0; i<n; ++i){
                int pos = upper_bound(begin(m[i]), end(m[i]), mid) - m[i].begin();
                num += pos;
            }
            if (num < k){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;
    }
};


