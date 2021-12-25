#include <bits/stdc++.h>
using namespace std;

// Longest Progression

int solve(vector<int> D) {
	int N = D.size();
	int maxLen = 0;


	for (int i = 0, j = 0; i < N; i = j) {
		while (j < N && D[i] == D[j]) ++j;

		maxLen = max(maxLen, j - i + 1);

		if (j < N) {
			maxLen = max(maxLen, j - i + 2);
		}

		if (j < N - 1 && D[j] + D[j + 1] == 2 * D[i]) {
			int end = j + 2;

			while (end < N && D[end] == D[i])
				end++;

			maxLen = max(maxLen, end - i + 1);
		}
	}

	return maxLen;
}

int main() {
	int T, j = 0;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<int> a(n, 0);
		for (auto &x : a) cin >> x;

		vector<int> D(n - 1);
		for (int i = 0; i < n - 1; ++i) {
			D[i] = a[i + 1] - a[i];
		}

		int ans = solve(D);
		reverse(begin(D), end(D));
		ans = max(ans, solve(D));
		cout << "Case #" << ++j << ": " << ans << "\n";
	}
}
