#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k<=0){
            return result;
        }
        
        auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int , int> b){
            return (nums1[a.first]+nums2[a.second]) > (nums1[b.first]+nums2[b.second]);
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);
        
        pq.emplace(0, 0);
        
        while(k-- > 0 && pq.size()){
            auto idxPair = pq.top(); pq.pop();
            result.push_back({nums1[idxPair.first], nums2[idxPair.second]});
            
            if (idxPair.first + 1 < nums1.size()){
                pq.emplace(idxPair.first+1, idxPair.second);
            }
            if (idxPair.first == 0 && idxPair.second+1 < nums2.size()){
                pq.emplace(idxPair.first, idxPair.second+1);
            }
        }
        return result;
    }
};