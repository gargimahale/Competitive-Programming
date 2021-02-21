#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        
        // base case
        if (boxes.size() == 1){
            return {0};
        }
        
        vector<int> temp;
        for (int i=0; i<boxes.size(); ++i){
            if (boxes[i] == '1'){
                temp.push_back(i);
            }
        }
        
        for (int i=0; i<boxes.size(); ++i){
            int cnt = 0;
            for (int j=0; j<temp.size(); ++j){
                if (i != temp[j]){
                    cnt += abs(i-temp[j]);
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};