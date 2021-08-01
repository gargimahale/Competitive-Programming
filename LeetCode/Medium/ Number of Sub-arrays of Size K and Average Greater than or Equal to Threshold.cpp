#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0, sum = 0, thresh = k * threshold;
        for (int i = 0, n = arr.size(); i < n; ++i) {
            sum += arr[i];

            if (i >= k) sum -= arr[i - k];
            if (i >= k - 1 && sum >= thresh) ++count;
        }
        return count;
    }
};