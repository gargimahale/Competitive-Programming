#include <bits/stdc++.h>
using namespace std;

class Solution {
    void popAndCheck(){
        tempH = hStack.back();
        hStack.pop_back();
        tempPos = pStack.back();
        pStack.pop_back();
        tempSize = tempH * (pos - tempPos);
        maxSize = max(maxSize, tempSize);
    }
    
    int largestHistogram(vector<int>& heights){
        n = heights.size();
        
        for (pos = 0; pos < n; ++pos){
            h = heights[pos];
            
            if (!hStack.size() || h >= hStack.back()){
                hStack.push_back(h);
                pStack.push_back(pos);
            }
            else if (h < hStack.back()){
                while (hStack.size() && hStack.back() > h){
                    popAndCheck();
                }
                
                hStack.push_back(h);
                pStack.push_back(tempPos);
            }
        }
        while(hStack.size()){
            popAndCheck();
        }
        return maxSize;
    }
public:
    int maxSize = 0;
    int h, pos, tempH, tempPos, tempSize = 0, n;
    vector<int> hStack, pStack;
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (!row) return 0;
        int col = matrix[0].size(), maxArea = 0;
        
        vector<int> heights(col, 0);
        
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestHistogram(heights));
        }
        return maxArea;
    }
};