#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string s) {
        unordered_map<string, int> mp;
        string temp;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                while (isdigit(s[i])) {
                    temp += s[i++];
                }
                temp.erase(0, temp.find_first_not_of('0'));
                mp[temp]++;
                temp = "";
            }
        }
        return mp.size();
    }
};