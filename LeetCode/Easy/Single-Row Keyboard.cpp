#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> check(26);
        for (int i = 0; i < keyboard.size(); ++i) {
            check[keyboard[i] - 'a'] = i;
        }

        int ans = check[word[0] - 'a'];
        for (int i = 1; i < word.size(); ++i) {
            ans += (abs(check[word[i - 1] - 'a'] - check[word[i] - 'a']));
        }
        return ans;
    }
};