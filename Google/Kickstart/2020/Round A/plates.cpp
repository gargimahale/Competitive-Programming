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
	int n, k, p;
	cin >> n >> k >> p;

	vector<vector<int>> stk(n);
	vector<int> plates;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> plates[j];
		}
		stk.push_back(plates)
	}

	vector<vector<int>> dp(n + 1, vector<int>(p + 1));



	// for (int i = 1; i<= n; ++i){
	// 	for (int j = 1; j<= k; ++j){
	// 		for (int l = 1; l <= p; ++l){
	// 			dp[i][j] = max(dp[i-1][j], )
	// 		}
	// 	}
	// }

	// return dp[n][p];
	return -1;
}

int32_t main() {
	IOS; SRAN;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int ans = solve();
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}