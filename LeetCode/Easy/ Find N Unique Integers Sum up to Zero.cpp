#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if (n <= 1){
            return {0};
        }
        
        if (n == 2){
            return {-1, 1};
        }
        
        for (int i = 1; i <= n/2; ++i){
            res.push_back(i);
            res.push_back(-i);
        }
        
        if (n > 2 && n%2 == 1){
            res.push_back(0);
        }
        return res;
    }
};