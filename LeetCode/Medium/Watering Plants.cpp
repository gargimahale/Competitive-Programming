#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int res = 0, can = capacity, n = plants.size();
        
        for (int i = 0; i < n; ++i){
            if (can < plants[i]){
                res += i*2;
                can = capacity;
            }
            can -= plants[i];
        }
        
        return res + n;
    }
};