#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        for (int i=0; i<s.size(); ++i){
            if (s[i] == '0') flag = true;
            else if (flag){
                if (s[i]) return false;
            }
        }
        return true;
    }
};