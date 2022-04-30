#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &mountainArr, int low, int high, int target, function<bool (int, int)> compare){
        int mid;
        while(low<=high){
            
            mid = low+(high-low)/2;
            int midEle = mountainArr.get(mid);
            
            if (midEle == target) return mid;
            
            if (compare(midEle, target)){
                high = mid-1;
            }
            
            else{
                low = mid+1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int border, low=0, high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        border = low;
        int f = binarySearch(mountainArr, 0, border, target, [](int a, int b){
           return a > b;
        });

        if (f != -1) return f;
        return binarySearch(mountainArr, border+1, n-1, target, [](int a, int b){
           return b > a;
        });
    }
};
