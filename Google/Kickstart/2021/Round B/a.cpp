#include <bits/stdc++.h>
using namespace std;

// Increasing Substring

int main(void) {
	int T, j = 0;
	cin >> T;
	while (T--) {
		int n, cnt = 1;
		cin >> n;
		string str;
		cin >> str;
		cout << "Case #" << ++j << ": ";
		if (str.size() > 0) cout << 1 << " ";
		for (int i = 1; i < str.size(); ++i) {
			if (str[i] > str[i - 1]) {
				++cnt;
			} else {
				cnt = 1;
			}
			cout << cnt << " ";
		}
		cout << "\n";
	}
}
