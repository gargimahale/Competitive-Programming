#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k, int count = 0) {
        unordered_map<int, int> c;
        
        for (int x: nums){
            c[x]++;
        } 
        
        for (auto it: c){
            if (k == 0){
                if (it.second >= 2){
                    ++count;
                }
                continue;
            }
            
            if (c.find(it.first + k) != c.end()){
                ++count;
            }
        }
        return count;
    }
};
