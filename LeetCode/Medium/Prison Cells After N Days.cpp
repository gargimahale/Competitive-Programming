#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int n = cells.size();
        vector<int> res(n), v;
        int cycle = 0;
        while(N-- > 0){
            for (int i=1; i<n-1; ++i){
                res[i] = cells[i-1] == cells[i+1];
            }
            if (v.empty()){
                v = res;
            }else if (v == res){
                N%=cycle;
            }
            ++cycle;
            cells = res;
        }
        return cells;
    }
};