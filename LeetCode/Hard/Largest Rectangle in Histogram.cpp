#include <bits/stdc++.h>
using namespace std;

class Solution {
    void popAndFindArea(int pos){
        tempH = log.back().first;
        tempPos = log.back().second;
        log.pop_back();
        int area = tempH * (pos-tempPos);
        maxArea = max(maxArea, area);
    }
public:
    vector<pair<int, int>> log;
    int maxArea = INT_MIN, tempH = 0, tempPos = 0, pos = 0;
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0){
            return 0;
        }
        
        if (n < 2){
            return heights[0];
        }
        
        for (pos = 0; pos < n; ++pos){
            if (log.empty() || heights[pos] > log.back().first){
                log.push_back({heights[pos], pos});
            }
            else if (heights[pos] < log.back().first){
                while(!log.empty() && heights[pos] < log.back().first){
                    popAndFindArea(pos);
                }
                log.push_back({heights[pos], tempPos});
            }
        }
        
        while(!log.empty()){
            popAndFindArea(pos);
        }
        
        return maxArea;
    }
};