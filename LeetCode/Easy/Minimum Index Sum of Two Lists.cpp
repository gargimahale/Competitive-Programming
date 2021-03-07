#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
        unordered_map<string, int> mp;
        for (int i=0; i<l1.size(); ++i) mp[l1[i]] = i;
        vector<string> ans;
        int currMin = INT_MAX;
        for (int i=0; i<l2.size(); ++i){
            if (mp.find(l2[i]) != mp.end()){
                if (mp[l2[i]]+i < currMin){
                    ans.clear();
                    ans.push_back(l2[i]);
                    currMin = mp[l2[i]]+i;
                }
                else if (mp[l2[i]]+i == currMin){
                    ans.push_back(l2[i]);
                }
            }
        }
        return ans;
    }
};