#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& w) {
        for (int& x: w){
            if (arr.empty()){
                arr.push_back(x);
            }
            else{
                arr.push_back(arr.back() + x);
            }
        }
    }
    
    int pickIndex() {
        int idx = rand() % arr.back();
        auto it = upper_bound(arr.begin(), arr.end(), idx);
        return it - arr.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */