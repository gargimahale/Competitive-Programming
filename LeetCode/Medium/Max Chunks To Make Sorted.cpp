#include <bits/stdc++.h>
using namespace std;

// Similar to Partition label
// It should be kept in mind that when a partition will be sorted 
// element with value x will be at index x (Here nos. are from 0 to n-1 in the array)

// So we can count the no. of end points of the partitions 
// At the end point of a partition max_ele of that partition will be at index max_ele
// So we take the max_ele untill it reaches index max_ele

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int i = 0, maxn = 0; i < n; ++i){
            maxn = max(maxn, arr[i]);
            if (maxn == i){
                ++ans;
            }
        }
        return ans;
    }
};