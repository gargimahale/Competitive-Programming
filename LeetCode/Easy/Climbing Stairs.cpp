#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs1(int n) {
        vector<int> dp(2, 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i){
            int count = dp[0]+dp[1];
            dp[0] = dp[1];
            dp[1] = count;
        }
        return dp[1];
    }

    int climbStairs2(int n) {
        int f = 1, s = 1;
        for (int i = 2; i <= n; ++i){
            int temp = f+s;
            f = s;
            s = temp;
        }
        return s;
    }
};