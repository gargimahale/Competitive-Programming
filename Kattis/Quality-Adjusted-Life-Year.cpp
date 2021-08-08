#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    double q, y, total = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> q >> y;
        total += (q * y);
    }
    cout << total << "\n";
}

int main(void) {
    solve();
}