#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> ps(101, -1);
        for (int i = 0; i < pieces.size(); ++i) {
            ps[pieces[i][0]] = i;
        }

        for (int i = 0; i < arr.size();) {
            int pos = ps[arr[i]];

            // piece not present
            if (pos == -1) {
                return false;
            }
            int j = 0;
            while (j < pieces[pos].size()) {
                if (arr[i++] != pieces[pos][j++]) {
                    return false;
                }
            }
        }
        return true;
    }
};