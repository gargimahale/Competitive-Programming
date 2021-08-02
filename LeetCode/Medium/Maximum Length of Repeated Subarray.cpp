#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        if (n == 0 || m == 0) return 0;

        vector<int> curr(n + 1, 0), prev(n + 1, 0);

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                    ans = max(ans, curr[j]);
                }
            }
            fill(begin(prev), end(prev), 0);
            swap(curr, prev);
        }
        return ans;
    }
};


