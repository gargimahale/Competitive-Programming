#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        if (m != n) return false;

        s.append(s);
        if (s.find(goal) != string::npos) {
            return true;
        }
        return false;
    }
};