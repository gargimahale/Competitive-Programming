#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string& s) {
        int n = s.size();
        if (n <= 1){
            return n;
        }
        int left = 0, right = 0;
        for (const char ch: s){
            if (ch == '(') ++right;
            else if (ch == ')' && right > 0) --right;
            else ++left;
        }
        return left + right;
    }
};