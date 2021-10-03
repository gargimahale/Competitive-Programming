#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int res = 0, maxF = 0, n = s.size();
        unordered_map<int, int> count;
        
        for (int i = 0; i < n; ++i){
            maxF = max(maxF, ++count[s[i]]);
            if (res - maxF < k){
                ++res;
            }
            else{
                count[s[i-res]]--;
            }
        }
        return res;
    }
};