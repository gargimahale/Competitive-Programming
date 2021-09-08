#include <bits/stdc++.h>
using namespace std;

// Time: O(N), Space: O(N)
string removeDuplicates(string s, int k) {
    stack<int> count;
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            count.push(1);
        }
        else if (++count.top() == k) {
            count.pop();
            s.erase(i - k + 1, k);
            i = i - k;
        }
    }
    return s;
}