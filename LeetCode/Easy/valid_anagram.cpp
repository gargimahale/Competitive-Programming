#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int ch[27] = {0};
        if (s.size() != t.size()) {
            return false;
        }
        for (int i=0; i<s.size(); ++i){
            ch[s[i]-'a']++;
            ch[t[i]-'a']--;
        }
        for (int x: ch) {
            if(ch < 0){
                return false;
            }
        }
        return true;
    }
};