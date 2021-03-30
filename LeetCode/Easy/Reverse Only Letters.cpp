#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)

class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        if (S.size() <= 1)
            return S;
        int i = 0, j = S.size() - 1;
        while (i < j)
        {
            if (isalpha(S[i]) && isalpha(S[j]))
            {
                swap(S[i], S[j]);
                ++i, --j;
            }
            else if (isalpha(S[i]) && !isalpha(S[j]))
            {
                --j;
            }
            else if (!isalpha(S[i]) && isalpha(S[j]))
                ++i;
            else
                ++i, --j;
        }
        return S;
    }
};