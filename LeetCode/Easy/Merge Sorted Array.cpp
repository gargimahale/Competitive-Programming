#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void display(vector<int>& nums){
        for (int& x: nums){
            cout << x << " ";
        }
        cout << "\n";
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cap = m+n-1, i = m-1, j = n-1;
        while(j >= 0){
            if (nums1[i] > nums2[j]){
                nums1[cap--] = nums1[i--];
            }
            else{
                nums1[cap--] = nums2[j--];
            }
        }
        display(nums1);
    }
};

int32_t main(){
    Solution S;
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};

    S.merge(nums1, 3, nums2, 3);
}