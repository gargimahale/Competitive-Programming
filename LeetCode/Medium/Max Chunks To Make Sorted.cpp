#include <bits/stdc++.h>
using namespace std;

// Similar to Partition label

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0, max_i = 0;
        for(int i=0; i<n; ++i){
            if (i == arr.size()) return cnt;
            max_i = max(max_i, arr[i]);
            if (max_i == i) ++cnt;
        }
        return cnt;
    }
};