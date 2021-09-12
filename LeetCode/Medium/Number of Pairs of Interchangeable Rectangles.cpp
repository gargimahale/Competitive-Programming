#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> map;
        for (auto rect: rectangles){
            map[(double) rect[0]/rect[1]]++;
        }
        long long res = 0;
        for (auto it: map){
            if (it.second > 1){
                res += ((it.second* (it.second-1))/2);
            }
        }
        
        return res;
    }
};