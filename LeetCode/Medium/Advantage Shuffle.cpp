#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B){
        multiset<int> S(begin(A), end(A));
        for (int i = 0; i < B.size(); ++i){
            auto p = *S.rbegin() <= B[i] ? S.begin() : S.upper_bound(B[i]);
            A[i] = *p;
            S.erase(p);
        }
        return A;
    }
};