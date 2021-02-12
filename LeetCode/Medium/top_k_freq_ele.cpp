#include<bits/stdc++.h>

using namespace std;

// Using bucket Sort - O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> U;
        for (int x: nums){
            U[x]++;
        }

        vector<vector<int>> buckets(nums.size()+1);

        for (auto& k: U){
            buckets[k.second].push_back(k.first);
        }
        reverse(begin(buckets), end(buckets));

        vector<int> res;

        for (auto& bucket: buckets){
            for (int x: bucket){
                res.push_back(x);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};



// Using Priority Queue - O(nlogn)