#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(begin(a), end(a));
    int ans = 0;
    for (int x: a){
        if (x <= b){
            ++ans;
            b -= x;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t, num = 1;
    cin >> t;
    while(t--) {
        int val = solve();
        cout << "Case #" << num++ << ": ";
    }
    return 0;
}

// TC: O(nlogn)
// SC: O(n)