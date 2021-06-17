#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int findShortestSubArray(vector<int>& nums) {
//         unordered_map<int, int> map;
//         for (int x: nums){
//             map[x]++;
//         }
//         int max_freq = 0;
//         vector<int> temp;
//         for (int i=0; i<nums.size(); ++i){
//             if (map[nums[i]] > max_freq){
//                 max_freq = map[nums[i]];
//             }
//         }
//         if (max_freq == 1){
//             return 1;
//         }

//         // elemets with highest degree;
//         for(auto x: map){
//             if (x.second == max_freq){
//                 temp.push_back(x.first);
//             }
//         }

//         int ans = INT_MAX;
//         for (int x: temp){
//             int i=0, j= nums.size()-1;
//             while(nums[i] != x){
//                 ++i;
//             }
//             while(nums[j] != x){
//                 --j;
//             }
//             ans = min(ans, j-i+1);
//         }
//         return ans;

//     }
// };


// OR

class Solution {
public:
    unordered_map<int, pair<pair<int, int>, int>> map; // (num: <(start, end), freq)>);


    int findShortestSubArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]].first = {i, i};
                map[nums[i]].second++;
            }
            else {
                map[nums[i]].first.second = i;
                map[nums[i]].second++;
            }
        }

        int max_freq = 0;
        for (int x : nums) {
            if (map[x].second > max_freq) {
                max_freq = map[x].second;
            }
        }

        if (max_freq == 1) {
            return 1;
        }

        int ans = INT_MAX;
        for (auto x : map) {
            if (x.second.second == max_freq) {
                ans = min(ans, (x.second.first.second - x.second.first.first + 1));
            }
        }
        return ans;
    }
};