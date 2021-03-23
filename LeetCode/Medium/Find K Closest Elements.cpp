#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x){
        int lo = 0, hi = arr.size() - k;
        while (lo < hi){
            int m = lo + (hi - lo) / 2;
            if (x - arr[m] > arr[m + k] - x)
                lo = m + 1;
            else
                hi = m;
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};