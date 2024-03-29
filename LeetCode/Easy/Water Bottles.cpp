#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, carry = 0;
        while (numBottles > 0) {
            numBottles += carry;
            carry = (numBottles % numExchange);
            ans += (numBottles / numExchange);
            numBottles /= numExchange;
        }
        return ans;
    }
};

int32_t main(){
    Solution sol;
    int bottles, numExchange;
    cin >> bottles >> numExchange;
    cout << sol.numWaterBottles(bottles, numExchange);
    return 0;
}