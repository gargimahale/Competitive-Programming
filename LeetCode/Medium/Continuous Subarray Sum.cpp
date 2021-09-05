#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Time: O(N), Space: O(N)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;
        int n = nums.size(), sum = 0, pre = 0;
        for (int i = 0; i < n; ++i){
            sum += nums[i];
            
            int mod = k == 0 ? sum : sum%k;
            if (mp.find(mod) != mp.end()){
                return true;
            }
            mp[pre] = true;
            pre = mod;
        }
        return false;
    }
};