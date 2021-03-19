#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K){
        struct mycomp{
            bool operator()(const pair<double, int> &a, const pair<double, int> &b){
                return a.first > b.first;
            }
        };
        
        // distance, index
        priority_queue<pair<double, int>, vector<pair<double, int>>, mycomp> m;

        for (int i = 0; i < points.size(); i++){
            double calc = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            m.push(make_pair(calc, i));
        }

        vector<vector<int>> ans;
        for (int i = 0; i < K; i++){
            ans.push_back(points[m.top().second]);
            m.pop();
        }
        return ans;
    }
};