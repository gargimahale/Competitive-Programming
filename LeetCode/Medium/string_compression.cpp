#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0, i = 0;
        while (i < chars.size()) {
            int j = i;
            while (j < chars.size() && chars[i] == chars[j]) {
                j++;
            }
            chars[idx++] = chars[i];
            if (j - i > 1) {
                string count = to_string(j - i);
                for (char ch : count) {
                    chars[idx++] = ch;
                }
            }
            i = j;
        }
        return idx;
    }
};