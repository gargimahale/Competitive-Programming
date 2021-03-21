#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

int solve(string str, int n, int k) {
	int cnt = 0;
	for (int i = 0; i < n / 2; ++i) {
		if (str[i] != str[n - i - 1]) {
			++cnt;
		}
	}
	return abs(cnt - k);
}

int32_t main() {
	IOS;
	init_code();
	int t, tc = 0;
	cin >> t;
	while (t--) {
		tc++;
		string str;
		int n, k;
		cin >> n >> k;
		cin >> str;
		cout << "Case #" << tc << ": " << solve(str, n, k) << endl;
	}
	return 0;
}