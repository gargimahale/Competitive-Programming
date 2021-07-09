#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int left = 1, right = n, res = -1;
    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (isBadVersion(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}