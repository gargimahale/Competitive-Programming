#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + ((right - left) / 2);
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(int argc, char **argv) {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}