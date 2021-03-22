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

int maxAscendingSum(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	int global = nums[0];
	int sum = nums[0];
	for (int i = 1; i < n; ++i) {
		if (nums[i] > nums[i - 1]) {
			sum += nums[i];
			global = max(sum, global);
		}
		else {
			sum = 0;
			sum += nums[i];
		}
	}
	return global;
}

int32_t main() {
	IOS
	SRAN
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	vector<int> a(t);
	for (int i = 0; i < t; ++i) cin >> a[i];
	cout << maxAscendingSum(a);
	return 0;
}