#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), top = -1;
        if (n == 0) return {};

        vector<int> res(n), s(n);

        for (int i = 0; i < n; ++i) {
            while (top > -1 && temperatures[s[top]] < temperatures[i]) {
                int idx = s[top--];
                res[idx] = i - idx;
            }
            s[++top] = i;
        }
        return res;
    }
};