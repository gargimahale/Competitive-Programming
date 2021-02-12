#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> map = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int l=0, r=num.size()-1;
        while(l<=r){
            if(map[num[l]] != num[r]){
                return false;
            }
            ++l, --r;
        }
        return true;
    }
};