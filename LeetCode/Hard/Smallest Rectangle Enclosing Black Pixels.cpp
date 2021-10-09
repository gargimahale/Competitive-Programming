#include <bits/stdc++.h>
using namespace std;

class Solution {
    int leftmost(vector<vector<char>>& image, int min, int max, bool horizontal){
        int l = min, r = max;
        while(l < r){
            int mid = l+(r-l)/2;
            if (!hasBlack(image, mid, horizontal)){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
    
    int rightmost(vector<vector<char>>& image, int min, int max, bool horizontal){
        int l = min, r = max;
        while(l < r){
            int mid = l + (r-l+1)/2;
            if (!hasBlack(image, mid, horizontal)){
                r = mid-1;
            }
            else{
                l = mid;
            }
        }
        return r;
    }
    
    bool hasBlack(vector<vector<char>>& image, int mid, bool horizontal){
        if (horizontal){
            for (int i = 0; i < image.size(); ++i){
                if (image[i][mid] == '1'){
                    return true;
                }
            }
        }
        else{
            for (int i = 0; i < image[0].size(); ++i){
                if (image[mid][i] == '1'){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = leftmost(image, 0, y, true);
        int right = rightmost(image, y, image[0].size()-1, true);
        int top = leftmost(image, 0, x, false);
        int bottom = rightmost(image, x, image.size()-1, false);
        return (right-left+1) * (bottom-top+1);
    }
};
