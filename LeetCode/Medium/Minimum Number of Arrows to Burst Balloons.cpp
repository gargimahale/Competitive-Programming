#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 1;
        if (points.size() == 0){
            return 0;
        }
        if (points.size() == 1){
            return cnt;
        }
        
        sort(begin(points), end(points));
        int minPt = points[0][1];
        for (int i=1; i<points.size(); ++i){
            if (points[i][0] > minPt){
                ++cnt, minPt = points[i][1];
            }
            else{
                minPt = min(minPt, points[i][1]);
            }
            
        }
        return cnt;
    }
};