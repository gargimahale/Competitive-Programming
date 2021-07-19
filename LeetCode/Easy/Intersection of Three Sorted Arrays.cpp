#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i = 0, j = 0, k = 0;
        vector<int> ans;

        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                ans.emplace_back(arr1[i]);
                ++i, ++j, ++k;
            }
            else if (arr2[j] < arr1[i]) {
                ++j;
            }
            else if (arr3[k] < arr1[i]) {
                ++k;
            }
            else {
                ++i;
            }
        }
        return ans;
    }
};

// TC: O(N), SC: O(1)