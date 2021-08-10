#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k) {
    vector<int> pieces(n);
    for (int x : pieces) cin >> x;
    sort(begin(pieces), end(pieces));
    int l = 0, r = n;
    int ans = 0;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if ((mid / k) > ans) {
            ans = mid / k;
        } else {
            r = mid;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
    return 0;
}