#include <vector>
using namespace std;

class Solution {
public:

    // Time: O(N), Space: O(N)
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        if (n <= 2){
           return water; 
        }
        
        vector<int> left(n, 0), right(n, 0);
        int leftMax = height[0], rightMax = height[n-1];
        
        for (int i = 1; i<n; ++i){
            left[i] = leftMax;
            right[n-i-1] = rightMax;
            
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[n-1-i]);
        }
        
        for (int i = 1; i<n-1; ++i){
            if (height[i] < left[i] && height[i] < right[i]){
                water += (min(left[i], right[i]) - height[i]);
            }
        }
        
        return water;
    }

    // Time: O(N), Space: O(1)
    int trap1(vector<int>& height) {
        int l = 0, r = height.size() - 1, water = 0, minHeight = 0;
        while (l < r) {
            while (l < r && height[l] <= minHeight) {
                water += minHeight - height[l++];
            }
            while (l < r && height[r] <= minHeight) {
                water += minHeight - height[r--];
            }
            minHeight = min(height[l], height[r]);
        }
        return water;
    }
};