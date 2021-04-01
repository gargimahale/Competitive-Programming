#include<bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> mp;
        char ans;
        for (char ch : s)
            mp[ch]++;

        for (int i = 0; i < t.size(); ++i)
        {
            if (mp[t[i]] == 0)
            {
                ans = t[i];
                break;
            }
            else
            {
                mp[t[i]]--;
            }
        }
        return ans;
    }
};