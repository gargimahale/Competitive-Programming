#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res, pos(26, 0);

        // Records the last position for each letter
        for (auto i = 0; i < S.size(); ++i) {
            pos[S[i] - 'a'] = i;
        }

        // Keep the max pos of the letters we have seen so far
        // if the ptr exceeds the max pos, we found the part

        for (int i = 0, left = 0, right = 0; i < S.size(); ++i) {
            right = max(right, pos[S[i] - 'a']);
            if (right == i) {
                res.push_back(i - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};


