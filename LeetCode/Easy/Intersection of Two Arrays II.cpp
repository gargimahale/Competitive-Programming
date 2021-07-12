#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

//         if (n > m){
//             return intersect(nums2, nums1);
//         }
        vector<int> ans;
//         unordered_map<int, int> mp;
//         for (int x: nums1){
//             mp[x]++;
//         }

//         for (int x: nums2){
//             if (mp.find(x) != mp.end()){
//                 mp[x]--;
//                 if (mp[x] == 0) mp.erase(x);
//                 ans.push_back(x);
//             }
//         }
//         return ans;

        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                ++i, ++j;
            }
            else if (nums1[i] < nums2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return ans;
    }
};


// TC: O(N) or O(Nlog N)