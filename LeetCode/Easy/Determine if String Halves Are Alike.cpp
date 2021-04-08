#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool halvesAreAlike(string s){
        unordered_set<char> S = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int a = 0, b = 0;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j){
            a += (S.count(s[i]) > 0 ? 1 : 0);
            b += (S.count(s[j]) > 0 ? 1 : 0);
        }
        return a == b;
    }
};