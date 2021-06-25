#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUniqueCount(string& s) {
        int cnt[26] = {0};
        for (char ch : s) {
            if (cnt[ch - 'a']++ > 0) return -1;
        }
        return s.length();
    }

    void maxUnique(vector<string>& arr, int index, string current, int& res) {
        if (index == arr.size() && maxUniqueCount(current) > res) {
            res = current.size();
            return;
        }

        if (index == arr.size()) {
            return;
        }

        maxUnique(arr, index + 1, current, res);
        maxUnique(arr, index + 1, current + arr[index], res);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int res = 0;
        maxUnique(arr, 0, "", res);
        return res;
    }
};