#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int res = 0;
        vector<int> vec;
        
        for (auto& row: grid){
            vec.insert(end(vec), begin(row), end(row));
        }
        nth_element(begin(vec), begin(vec) + vec.size()/2, end(vec));
        
        for (int i = 0; i < vec.size(); ++i){
            if (abs(vec[vec.size()/2] - vec[i]) % x){
                return -1;
            }
            res += abs(vec[vec.size()/2] - vec[i])/x;
        }
        return res;
    }
};