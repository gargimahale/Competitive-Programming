#include <bits/stdc++.h>

using namespace std;

/*
Trick:-
The pairs which are on the left of the single element, will have the first element in an even position and 
the second element at an odd position. All the pairs which are on the right side of the single element will 
have the first position at an odd position and the second element at an even position. Use this fact to decide 
whether to go to the left side of the array or the right side.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i < j){
            int mid = i+(j-i)/2;
            if ((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1])){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        return nums[i];
    }
};