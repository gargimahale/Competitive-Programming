#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        int i = num1.size()-1, j = num2.size()-1;
        while(i >= 0 || j >=0 || carry){
            int temp = (i >= 0 ? (num1[i]-'0'): 0) + (j >= 0 ? (num2[j]-'0'): 0);
            carry += temp;
            ans += to_string(carry%10);
            carry /= 10;
            --i, --j;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};

// Time: O(N+M), Space: O(max(N, M))