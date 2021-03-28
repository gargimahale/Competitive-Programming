#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reinitializePermutation(int n)
    {
        string real;
        for (int i = 0; i < n; ++i)
        {
            real += (i + '0');
        }
        string temp = real;
        string perm = real;
        int cnt = 0;
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < perm.size(); ++i)
            {
                if (i % 2 == 0)
                {
                    temp[i] = perm[i / 2];
                }
                else
                {
                    temp[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            perm = temp;
            if (perm == real)
            {
                ++cnt;
                break;
            }
            else
            {
                ++cnt;
            }
        }
        return cnt;
    }
};