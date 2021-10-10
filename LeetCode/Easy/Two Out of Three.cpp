#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<vector<bool>> count(3, vector<bool>(101));
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i){
            count[0][nums1[i]] = true;
        }

        for (int i = 0; i < nums2.size(); ++i){
            count[1][nums2[i]] = true;
        }

        for (int i = 0; i < nums3.size(); ++i){
            count[2][nums3[i]] = true;
        }

        for (int i = 1; i <= 100; ++i){
            if (count[0][i] + count[1][i] + count[2][i] > 1){
                res.push_back(i);
            }
        }
        return res;
    }
};