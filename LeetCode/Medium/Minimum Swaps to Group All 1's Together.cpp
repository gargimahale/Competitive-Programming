#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        if (n < 3) return 0;
        int  numOnes = 0;
        for (int x : data) {
            if (x == 1) ++numOnes;
        }

        int i = 0, j = 0, c = 0, m = 0;
        while (j < n) {
            while (j < n && j - i < numOnes) {
                if (data[j++] == 1) ++c;
            }

            m = max(c, m);
            if (j == n) break;

            if (data[i++] == 1) --c;
        }
        return numOnes - m;
    }
};