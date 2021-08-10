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
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    const vector<pair<int, int>> cost = {{6, 15}, {8, 20}, {10, 25}};
    for (int i = 0; i <= n; ++i) {

    }
    return dp[n];
}

int32_t main() {
    IOS; SRAN;
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}