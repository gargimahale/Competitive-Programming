#include<bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)

class Solution{
public:
    string originalDigits(string s){
        vector<int> a(10, 0);
        vector<int> cnt(128, 0);
        for (char ch : s)
            cnt[ch]++;

        // Unique to them
        a[0] = cnt['z'];
        a[2] = cnt['w'];
        a[4] = cnt['u'];
        a[6] = cnt['x'];
        a[8] = cnt['g'];

        // common
        a[3] = cnt['h'] - a[8];
        a[5] = cnt['f'] - a[4];
        a[7] = cnt['v'] - a[5];
        a[1] = cnt['o'] - a[0] - a[2] - a[4];
        a[9] = cnt['i'] - a[5] - a[6] - a[8];

        string res;
        for (int i = 0; i < 10; ++i){
            if (a[i] > 0){
                res += string(a[i], '0' + i);
            }
        }
        return res;
    }
};