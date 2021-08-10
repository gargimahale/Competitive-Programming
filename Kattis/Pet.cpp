#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<int> a(5, 0);
	int sum = 0, prev = 0, p = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		prev = a[0] + a[1] + a[2] + a[3];
		if (sum < prev) {
			p = i + 1;
			sum = prev;
		}
	}
	cout << p << " " << sum;
}

int main(void) {
	solve();
}