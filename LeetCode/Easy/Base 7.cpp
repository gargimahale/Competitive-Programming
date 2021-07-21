#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        int res = 0;
        for (int i = 0; num != 0; num /= 7) {
            res += pow(10, i++) * (num % 7);
        }
        return to_string(res);
    }
};