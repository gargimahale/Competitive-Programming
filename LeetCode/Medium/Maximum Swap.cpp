#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        if (num <= 0){
            return 0;
        }
        string str = to_string(num);
        
        int maxIdx = -1, maxDigit = -1, leftIdx = -1, rightIdx = -1;

       for (int i = str.size()-1; i >= 0; --i){
           if (str[i] > maxDigit){
               maxDigit = str[i];
               maxIdx = i;
               continue;
           }
           if (str[i] < maxDigit){
               leftIdx = i;
               rightIdx = maxIdx;
           }
       }
        
        if (leftIdx == -1){
            return num;
        }
        swap(str[leftIdx], str[rightIdx]);
        return stoi(str);
    }
};