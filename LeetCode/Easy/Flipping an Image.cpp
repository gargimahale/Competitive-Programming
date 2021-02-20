#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i=0; i<A.size(); ++i){
            reverse(begin(A[i]), end(A[i]));
            for(int j=0; j<A[i].size(); ++j){
                if (A[i][j] == 0){
                    A[i][j] = 1;
                }
                else{
                    A[i][j] = 0;
                }
            }
        }
        return A;
    }
};