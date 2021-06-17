#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {

        if (arr.size() <= 2) return 0;
        int diff = arr[1] - arr[0] >= 0 ? INT_MAX : INT_MIN;
        for (int i = 1; i < arr.size(); ++i) {
            int val = arr[i] - arr[i - 1];
            if (val < 0) {
                diff = max(diff, val);
            }
            else {
                diff = min(diff, val);
            }
        }
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] + diff != arr[i + 1]) {
                return arr[i] + diff;
            }
        }
        return arr[0];
    }
};