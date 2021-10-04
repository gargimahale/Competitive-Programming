#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum1 = 0, sum2 = 0, ans = 0;
        vector<int> t = arr;
        sort(begin(t), end(t));
        for (int i = 0; i < arr.size(); ++i){
            sum1 += t[i];
            sum2 += arr[i];
            if (sum1 == sum2){
                ++ans;
            }
        }
        return ans;
    }
};