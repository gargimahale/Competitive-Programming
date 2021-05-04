#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> map;
        for (auto a: A){
            for (auto b: B){
                ++map[a+b];
            }
        }
        for (auto c: C){
            for(auto d: D){
                auto it = map.find(-c-d);
                if (it != map.end()){
                    res += it->second;
                }
            }
        }
        return res;
    }
};