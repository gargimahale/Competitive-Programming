#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> result;
        for (int i=0, j=0; i<a.size() && j<b.size(); a[i][1] < b[j][1] ? ++i : ++j){
            int start = max(a[i][0], b[j][0]);
            int end = min(a[i][1], b[j][1]);
            if (start <= end){
                result.push_back({start, end});
            }
        }
        return result;
    }
};
