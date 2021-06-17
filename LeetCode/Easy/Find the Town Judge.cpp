#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (trust.size() == 1) {
            return trust[0][1];
        }
        if (N == 1) {
            return 1;
        }

        vector<int> cnt(N + 1);
        for (int i = 0; i < trust.size(); ++i) {
            --cnt[trust[i][0]];
            ++cnt[trust[i][1]];
        }

        for (int i = 0; i <= N; ++i) {
            if (cnt[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};