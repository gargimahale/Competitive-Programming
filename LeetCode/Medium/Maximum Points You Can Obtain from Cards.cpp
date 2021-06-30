#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0, n = cardPoints.size(), t = 0;
        for (int i = n - k; i < n; ++i) res += cardPoints[i];
        for (int i = 0, t = res; i < n && i < k; ++i) {
            t -= cardPoints[n - k + i];
            t += cardPoints[i];
            res = max(res, t);
        }
        return res;
    }
};