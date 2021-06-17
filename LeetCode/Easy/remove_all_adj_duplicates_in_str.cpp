#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for (int i = 0; i < S.size(); ++i) {
            if (ans.back() == S[i]) {
                ans.pop_back();
            }
            else {
                ans.push_back(S[i]);
            }
        }
        return ans;
    }
};
