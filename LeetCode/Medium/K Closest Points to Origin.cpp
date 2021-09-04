#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(Nlogk)
    // SC: O(1)

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Partial Sort---------
        // partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
        //     return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        // });
        // return vector<vector<int>>(points.begin(), points.begin() + K);
        

        // n-th element---------
        // nth_element(points.begin(), points.begin() + K - 1, points.end(), [](vector<int>& p, vector<int>& q) {
        //     return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        // });
        // return vector<vector<int>>(points.begin(), points.begin() + K); 


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