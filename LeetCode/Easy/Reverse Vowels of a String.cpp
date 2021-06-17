#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int dict[126] = {0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;


        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (dict[s[i]] && dict[s[j]]) {
                swap(s[i++], s[j--]);
            }
            else if (dict[s[i]] > 0) {
                --j;
            }
            else {
                ++i;
            }
        }
        return s;
    }
};