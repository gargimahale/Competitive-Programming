#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0, end = chars.size(), index = 0, temp = 0;
        while(start < end){
            temp = start;
            while(temp < end && chars[start] == chars[temp]) ++temp;
            chars[index++] = chars[start];
            if (temp - start > 1){
                string new_count = to_string(temp-start);
                for (char ch: new_count){
                    chars[index++] = ch;
                }
            }
            start = temp;
        }
        return index;
    }
};