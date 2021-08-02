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
const int N = 1e5 + 5;



void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

int solve() {

}

int32_t main() {
	IOS
	SRAN
	init_code();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}