#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0;
        for (int i=2, j=1; i<A.size(); ++i){
            if (A[i] - A[i-1] != A[j] - A[j-1]){
                j = i;
            }
            cnt += (i-j);
        }
        return cnt;
    }
};