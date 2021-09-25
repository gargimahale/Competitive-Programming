#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int& ele: nums) sum += ele;
        
        if ((sum + target) % 2 == 1 || target > sum || target < -sum){
            return 0;
        }
        
        int newSum = (sum + target) >> 1;
        vector<int> dp(newSum+1, 0);
        
        dp[0] = 1;
        for (int i = 0; i<nums.size(); ++i){
            for (int j = newSum; j >= nums[i]; --j){
                dp[j] += dp[j-nums[i]];
            }
        }
        
        return dp[newSum];
    }
};
