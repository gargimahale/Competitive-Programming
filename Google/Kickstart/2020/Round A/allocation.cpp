#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define SRAN srand(chrono::high_resolution_clock::now().time_since_epoch().count())
#define gc getchar_unlocked
#define int long long
#define endl "\n"
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
const int MOD = 1e9 + 7;

int solve() {
    int n, b;
    cin >> n >> b;
    vector<int> houses(n, 0);
    for (int i = 0; i < n; ++i) cin >> houses[i];
    sort(begin(houses), end(houses));

    int cnt = 0;
    for (int i = 0; i < n && b - houses[i] >= 0; ++i) {
        ++cnt;
        b -= houses[i];
    }
    return cnt;
}

int32_t main() {
    IOS; SRAN;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int ans = solve();
        cout << "Case #" << i + 1 << ":" << ans << endl;
    }
    return 0;
}