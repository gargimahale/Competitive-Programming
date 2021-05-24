#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size();
        for (int i = n - 1; i >= 0 && K != 0; --i) {
            K += A[i];
            A[i] = K % 10;
            K /= 10;
        }
        while (K > 0) {
            A.insert(A.begin(), K % 10);
            K /= 10;
        }
        return A;
    }
};