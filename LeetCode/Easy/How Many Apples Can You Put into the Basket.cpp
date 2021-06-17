#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int cnt = 0;
        for (int i = 0, wt = 5000; i < arr.size() && wt >= 0; ++i) {
            if (arr[i] <= wt) {
                ++cnt, wt -= arr[i];
            }
        }
        return cnt;
    }
};