#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int currIdx = 0;
        for (int i=0; i<temp.size(); ++i){
            if (mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = currIdx;
                ++currIdx;
            }
        }
        
        vector<int> ans;
        for(int i=0; i<arr.size(); ++i){
            ans.push_back(mp[arr[i]]+1);
        }
        return ans;
    }
};