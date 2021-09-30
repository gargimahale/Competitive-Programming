#include <bits/stdc++.h>
using namespace std;

class Solution {
    void popAndCheck(){
        tempH = hStack.back();
        hStack.pop_back();
        tempPos = pStack.back();
        pStack.pop_back();
        tempSize = tempH * (pos - tempPos);
        maxSize = max(tempSize, maxSize);
    }
public:
    int h, pos, tempH, tempPos, tempSize = 0, maxSize = INT_MIN;
    vector<int> hStack, pStack;
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n < 2){
            return heights[0]; 
        }
        
        for (pos = 0; pos < n; ++pos){
            h = heights[pos];
            
            if (!hStack.size() || h > hStack.back()){
                hStack.push_back(h);
                pStack.push_back(pos);
            }
            else if (h < hStack.back()){
                while(hStack.size() && h < hStack.back()){
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
};