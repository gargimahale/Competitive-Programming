#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int map(char c){
        switch (c){
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'I':
                return 1;
            case 'V':
                return 5;
            default:
                return 0;
        }
    }
    int romanToInt(string s) {
        int result = 0;
        for (size_t i = 0; i < s.size()-1; ++i){
            if (map(s[i]) >= map(s[i+1])) {
                result += map(s[i]);
            }else{result -= map(s[i]);}
        }
        result += map(s[s.size()-1]);
        return result;
    }
};
