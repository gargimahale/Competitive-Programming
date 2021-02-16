#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int calculateSoldiers(vector<int>& a){
        int l =0, h = a.size()-1;
        while(l <= h){
            int mid = l+(h-l)/2;
            if (a[mid] == 0){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> m;
        for(int i=0; i<mat.size(); ++i){
            auto x = calculateSoldiers(mat[i]);
            m.push_back({x, i});
        }
        
        sort(begin(m), end(m), [&](pair<int, int> a, pair<int, int> b){
            return a.first == b.first ? a.second < b.second : a.first < b.first; 
        });
        
        vector<int> res;
        for (auto it = begin(m); k>0; ++it, --k){
            res.push_back(it->second);
        }
        return res;
    }
};

