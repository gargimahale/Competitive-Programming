#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(Nlogk)
    // SC: O(1)

    vector<vector<int>> kClosest_2(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        int n = points.size();
        
        for (int i = 0; i<n; ++i){
            pq.push({(pow(points[i][0], 2) + (pow(points[i][1], 2))), i});
            
            if (pq.size() > k){
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i< min(n, k); ++i){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return ans;
    }
};