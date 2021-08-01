#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int idx = n - 2;

        while (idx >= 0) {
            if (arr[idx] > arr[idx + 1]) {
                break;
            }
            --idx;
        }

        if (idx < 0) return arr;

        //find largest element at right of index which is less than A[index];
        int max_idx = INT_MIN, pos = 0;
        for (int i = idx + 1; i < n; ++i) {
            if (arr[i] < arr[idx] && arr[i] > max_idx) {
                max_idx = arr[i];
                pos = i;
            }
        }

        swap(arr[idx], arr[pos]);
        return arr;
    }
};