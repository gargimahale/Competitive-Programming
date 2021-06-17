#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bit_count(int bits) {
        int cnt = 0;
        for (; bits; bits &= bits - 1)
            ++cnt;
        return cnt;
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bit_count(h) + bit_count(m) == num) {
                    const string hour = to_string(h);
                    const string minute = m < 10 ? "0" + to_string(m) : to_string(m);
                    result.emplace_back(hour + ":" + minute);
                }
            }
        }
        return result;
    }
};