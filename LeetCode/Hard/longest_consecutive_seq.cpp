#include <bits/stdc++.h>
using namespace std;

// Time: O(N), Space: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());
        int best = 0;
        for (int x : nums) {
            if (S.find(x - 1) == S.end()) {
                int y = x + 1;
                while (S.find(y) != S.end()) {
                    y += 1;
                }
                best = max(best, y - x);
            }
        }
        return best;
    }
};

// Time: O(NlogN), Space: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2){
            return n;
        }
        
        sort(begin(nums), end(nums));
        
        int curr = 0, maxLen = 0;
        for (int i = 0; i < n; ++i){
            if (nums[i] != nums[i-1]){
                if (nums[i] == nums[i-1]+1){
                    ++curr;
                }
            }
            else{
                maxLen = max(maxLen, curr);
                curr = 1;
            }
        }
        
        return (int)max(maxLen, curr);
    }
};