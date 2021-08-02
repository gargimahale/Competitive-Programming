#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define SRAN srand(chrono::high_resolution_clock::now().time_since_epoch().count());
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
// const int MOD = 1e9 + 7;

const int N = 51;
const int P = 51 * 30;

int n, p, k;
int a[N][31], pref[N][31];
int cache[N][P];

int solve(int idx, int taken) {
	if (taken == p)
		return 0;
	if (idx > n || taken > p)
		return -1e9;
	if (cache[idx][taken] != -1)
		return cache[idx][taken];
	int ans = -1e9;
	for (int i = 0; i <= k; ++i) {
		ans = max(ans, pref[idx][i] + solve(idx + 1, taken + i));
	}
	return cache[idx][taken] = ans;
}

int32_t main() {
	IOS
	SRAN
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	cin >> t;
	while (t--) {
		tc++;
		cin >> n >> k >> p;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k; ++j) {
				cin >> a[i][j];
				pref[i][j] = pref[i][j - 1] + a[i][j];
			}
		}

		memset(cache, -1, sizeof(cache));
		int ans = solve(1, 0);
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}