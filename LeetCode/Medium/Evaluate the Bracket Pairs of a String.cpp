#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> mp;
        for (auto x : knowledge)
        {
            mp[x[0]] = x[1];
        }

        string ans = "";
        for (int i = 0; i < s.size(); ++i)
        {
            string temp = "";
            if (s[i] == '(')
            {
                ++i;
                while (s[i] != ')')
                {
                    temp += s[i++];
                }
                if (mp.find(temp) != mp.end())
                {
                    ans += mp[temp];
                }
                else
                {
                    ans += '?';
                }
                // ++i;
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};