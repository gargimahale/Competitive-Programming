#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), i = 0, j = n-1;
        if (n < 2){
            return 0;
        }
        
        while(colors[0] == colors[j]) --j;
        while(colors[n-1] == colors[i]) ++i;
        
        return max(j, n-i-1);
    }
};