#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findTheWinner(int n, int k){
        vector<int> A;
        for (int i = 1; i <= n; ++i){
            A.push_back(i);
        }
        int idx = k - 1;
        for (int i = 0; i < n - 1; ++i){
            A.erase(A.begin() + idx);
            idx = (idx + k - 1) % A.size();
        }
        return A[0];
    }
};