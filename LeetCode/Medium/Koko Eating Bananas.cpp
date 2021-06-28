#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int getMax(vector<int>& piles) {
        int max_val = INT_MIN;
        for (int ele : piles) {
            if (ele > max_val) {
                max_val = ele;
            }
        }
        return max_val;
    }

    bool canEatAllBananas(vector<int>& piles, int k, int h) {
        int count_hr = 0;
        for (int i = 0; i < piles.size(); ++i) {
            count_hr += piles[i] / k;
            if (piles[i] % k != 0) {
                ++count_hr;
            }
        }
        return count_hr <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = getMax(piles);

        int left = 1, right = max_pile;

        while (left <= right) {
            int k = left + (right - left) / 2;
            if (canEatAllBananas(piles, k, h)) {
                right = k - 1;
            }
            else {
                left = k + 1;
            }
        }
        return left;
    }
};