#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int thirdMax(vector<int> &nums){
        set<int> S;
        for (int x : nums){
            S.insert(x);
            if (S.size() > 3)
                S.erase(S.begin());
        }
        return S.size() == 3 ? *S.begin() : *S.rbegin();
    }
};